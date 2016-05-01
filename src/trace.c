/*
** trace.c for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Sun May 01 08:56:04 2016 Bastien DHIVER
** Last update Sun May  1 10:17:31 2016 florian videau
*/

#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftrace.h"

int	be_the_child(t_args *args)
{
  int	fd;

  if ((fd = open("/dev/null", O_WRONLY)) == -1)
    return (1);
  if (dup2(fd, 1) == -1 || dup2(fd, 2) == -1)
    return (1);
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (execve(args->av[0], args->av, args->env) == -1)
    return (display_error(errno), 1);
  return (0);
}

int	one_more_step(int *status, t_call *call, unsigned long *opcode)
{
  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, status, 0) == -1)
    return (display_error(errno), 1);
  if (aff_end_signal(*status))
    {
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno), 1);
      if (!(*opcode = ptrace(PTRACE_PEEKTEXT, g_pid,
			     call->regs.rip, call->regs)))
	return (display_error(errno), 1);
      return (0);
    }
  return (1);
}

unsigned long	be_the_parent_rec(int *status, t_call *call,
				  t_rex *rex, t_call_type calltype)
{
  unsigned long addr;
  unsigned long opcode;
  char		*fct_name;

  if (!(opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
    return (display_error(errno), 0);
  addr = (calltype == RELATIVE ? addr_relative(call, opcode, rex->w) :
	  addr_indirect(opcode, call, rex));
  fct_name = get_name_from_addr(addr);
  printf("Entering function %s at 0x%llx\n", fct_name, (long_stuff)addr);
  free(fct_name);
  if (one_more_step(status, call, &opcode))
    return (0);
  while (!RET(opcode) && aff_end_signal(*status))
    {
      bzero(rex, sizeof(t_rex));
      while (!CALL(opcode) && !RET(opcode) && (opcode & 0xF0) != 0x40
	     && !WIFEXITED(*status))
	if (one_more_step(status, call, &opcode))
	  return (0);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(status, call, &opcode))
	    return (0);
	  if (aff_end_signal(*status))
	      aff_syscall(call);
	  else
	    return (0);
	}
      if ((opcode & 0xF0) == 0x40)
	{
	  rex->w = opcode & 0x8;
	  rex->r = opcode & 0x4;
	  rex->x = opcode & 0x2;
	  rex->b = opcode & 0x1;
	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, ++call->regs.rip);
	}
      if (RET(opcode))
	{
	  fct_name = get_name_from_addr(addr);
	  printf("Leaving function %s\n", fct_name);
	  return (free(fct_name), opcode);
	}
      else if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(status, call, rex, RELATIVE)))
	    return (0);
	}
      else if (INDCALL(opcode))
	if (!(be_the_parent_rec(status, call, rex, INDIRECT)))
	  return (0);
      if (one_more_step(status, call, &opcode))
	return (0);
    }
  fct_name = get_name_from_addr(addr);
  printf("Leaving function %s\n", fct_name);
  return (free(fct_name), opcode);
}

int	during_signal_to_appear(unsigned long opcode, int *status,
				t_call *call, t_rex *rex)
{
  while (!opcode || !CALL(opcode))
    if (one_more_step(status, call, &opcode))
      return (1);
  if (SYSCALL(opcode))
    {
      if (one_more_step(status, call, &opcode))
	return (1);
      if (aff_end_signal(*status))
	aff_syscall(call);
    }
  if (RELCALL(opcode))
    {
      if (!(opcode = be_the_parent_rec(status, call, rex, RELATIVE)))
	return (1);
    }
  else if (INDCALL(opcode))
    {
      if (!(opcode = be_the_parent_rec(status, call, rex, INDIRECT)))
	return (1);
    }
  if (one_more_step(status, call, &opcode))
    return (1);
  return (0);
}

int		be_the_parent(t_call *call, char *pathname)
{
  int		status;
  unsigned long	opcode;
  t_rex		rex;

  if (load_elf(pathname, &g_bin))
    return (1);
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (aff_end_signal(status))
    {
      bzero(&rex, sizeof(t_rex));
      if (during_signal_to_appear(opcode, &status, call, &rex))
	return (1);
    }
  return (0);
}
