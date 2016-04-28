/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Last update Thu Apr 28 23:10:57 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftrace.h"

int	be_the_child(t_args *args)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (execve(args->av[0], args->av, args->env) == -1)
    return (display_error(errno), 1);
  return (1);
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
      if (!(*opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
	return (display_error(errno), 1);
      return 0;
    }
  return 1;
}

unsigned long addr_indirect(unsigned long opcode)
{
  return opcode;
}

unsigned long addr_relative(t_call *call, unsigned long opcode, char rexw)
{
  int		offset;
  unsigned long	call_addr;

  offset = (int)((opcode >> 8));
  if (rexw)
    {
      offset = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 1);
      call_addr = call->regs.rip + offset + 9;
    }
  else
    {
      /* int val; */
      /* val = offset & 0xFFFFFF; */
      call_addr = call->regs.rip + offset + 5;
    }
  return call_addr;
}

unsigned long	be_the_parent_rec(int *status, t_call *call, t_rex *rex, int indent, t_call_type calltype)
{
  int	i;
  unsigned long addr;
  unsigned long opcode;

  if (!(opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
    return (display_error(errno), 0);
  /* addr = calltype == RELATIVE?addr_relative(call, opcode, rex->w):addr_indirect(opcode); */
  (void) addr;
  (void) calltype;
  /* addr = addr; */
  if (one_more_step(status, call, &opcode))
    return (0);
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Entering function : at 0x%llx\n", (unsigned long long)call->regs.rip);
  while(!RET(opcode) && aff_end_signal(*status))
    {
      bzero(&rex, sizeof(t_rex));
      while (!CALL(opcode) && !RET(opcode) && !WIFEXITED(*status))
	if (one_more_step(status, call, &opcode))
	  return (0);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(status, call, &opcode))
	    return (0);
	  if (aff_end_signal(*status))
	    {
	      i = -1;
	      while (++i < indent)
		printf(" ");
	      aff_syscall(call);
	    }
	  else
	    return (0);
	}
      /* if ((opcode & 0xF0) == 0x40) */
      /* 	{ */
      /* 	  rex->w = opcode & 0x8; */
      /* 	  rex->r = opcode & 0x4; */
      /* 	  rex->x = opcode & 0x2; */
      /* 	  rex->b = opcode & 0x1; */
      /* 	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, ++call->regs.rip); */
      /* 	} */
      if (RET(opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("Leaving function\n");
	  return opcode;
	}
      else if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(status, call, rex, indent + 1, RELATIVE)))
	    return 0;
	}
      else if (INDCALL(opcode))
	{
	  if (!(be_the_parent_rec(status, call, rex, indent + 1, INDIRECT)))
	    return 0;
	}
      if (one_more_step(status, call, &opcode))
	return 0;
    }
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Leaving function\n");
  return (opcode);
}

int		be_the_parent(t_call *call, char *pathname)
{
  int		status;
  unsigned long	opcode;
  t_rex		rex;

  if (load_elf(pathname))
    return (1);
  if (gelf_getclass(g_bin.e) == ELFCLASS32)
    {
#define ELF_IS_32_
    }
  if (gelf_getclass(g_bin.e) != ELFCLASS32)
    {
#undef ELF_IS_32_
    }
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (aff_end_signal(status))
    {
      bzero(&rex, sizeof(t_rex));
      while (!opcode || !CALL(opcode))
	if (one_more_step(&status, call, &opcode))
	  return (1);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(&status, call, &opcode))
	    return (1);
	  if (aff_end_signal(status))
	    aff_syscall(call);
	}
      if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, 0, RELATIVE)))
	    return 1;
	}
      else if (INDCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, 0, INDIRECT)))
	    return 1;
	}
      if (one_more_step(&status, call, &opcode))
	return (1);
    }
  return (0);
}
