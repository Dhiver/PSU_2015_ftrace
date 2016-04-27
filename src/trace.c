/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Tue Apr 26 10:56:32 2016 florian videau
*/

#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/ftrace.h"

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
  if (!WIFEXITED(*status))
    {
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno), 1);
      if (!(*opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
	return (display_error(errno), 1);
    }
  return 0;
}

int	be_the_parent_rec(int *status, t_call *call, unsigned long *opcode, int indent)
{
  int	i;

  if (one_more_step(status, call, opcode))
    return 1;
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Entering function : at 0x%llx\n", (unsigned long long) call->regs.rip);
  while(!RET(*opcode) && !WIFEXITED(*status))
    {
      while (!CALL(*opcode) && !RET(*opcode) && !WIFEXITED(*status))
	if (one_more_step(status, call, opcode))
	  return 1;
      if (SYSCALL(*opcode))
	{
	  if (one_more_step(status, call, opcode))
	    return 1;
	  if (aff_end(*status))
	    {
	      i = -1;
	      while (++i < indent)
		printf(" ");
	      main_printing(call);
	    }
	  else
	    return 1;
	}
      if (RET(*opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("Leaving function\n");
	  return 0;
	}
      else if (RELCALL(*opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("RELATIVE\n");
	  if (be_the_parent_rec(status, call, opcode, indent + 1))
	    return 1;
	}
      else if (INDCALL(*opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("INDIRECT\n");
	  if (be_the_parent_rec(status, call, opcode, indent + 1))
	    return 1;
	}
      if (one_more_step(status, call, opcode))
	return 1;
    }
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Leaving function\n");
  return (0);
}

/*
**_start function
*/
int	be_the_parent(t_call *call, char *pathname)
{
  int		status;
  unsigned long	opcode;

  if (load_elf(pathname))
    return (1);
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (!WIFEXITED(status))
    {
      while (!opcode || !CALL(opcode))
	if (one_more_step(&status, call, &opcode))
	  return (1);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(&status, call, &opcode))
	    return (1);
	  if (aff_end(status))
	    main_printing(call);
	}
      else
	if (be_the_parent_rec(&status, call, &opcode, 0))
	  return (1);
	else if (one_more_step(&status, call, &opcode))
	  return (1);
    }
  return (0);
}
