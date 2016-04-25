/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Mon Apr 25 17:44:28 2016 florian videau
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

int	be_the_parent_rec(int *status, t_call *call, unsigned long *opcode, int indent)
{
  int	i;

  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  *opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Entering function : at %llx\n", (unsigned long long) call->regs.rip);
  while(!RET(*opcode) && !WIFEXITED(*status))
    {
      while (!CALL(*opcode) && !RET(*opcode) && !WIFEXITED(*status))
  	{
  	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
  	    return (display_error(errno), 1);
  	  if (waitpid(g_pid, status, 0) == -1)
  	    return (display_error(errno), 1);
	  if (!WIFEXITED(*status))
	    {
	      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
		return (display_error(errno));
	      *opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
	    }
  	}
      if (SYSCALL(*opcode))
	{
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno));
	  if (waitpid(g_pid, status, 0) == -1)
	    return (display_error(errno));
	  if (!WIFEXITED(status))
	    {
	      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &call->regs) == -1)
	      	return (display_error(errno));
	      *opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
	      i = -1;
	      while (++i < indent)
		printf(" ");
	      main_printing(call);
	    }
	  else
	    printf("exit\n");
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
	  be_the_parent_rec(status, call, opcode, indent + 1);
	}
      else if (INDCALL(*opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("INDIRECT\n");
	  be_the_parent_rec(status, call, opcode, indent + 1);
	}
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno), 1);
      if (waitpid(g_pid, status, 0) == -1)
	return (display_error(errno), 1);
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno));
      *opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);

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
int	be_the_parent(t_call *call)
{
  int		status;
  unsigned long	opcode;

  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (!WIFEXITED(status))
    {
      while (!opcode || !CALL(opcode))
	{
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno), 1);
	  if (waitpid(g_pid, &status, 0) == -1)
	    return (display_error(errno), 1);
	  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	    return (display_error(errno));
	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
	}
      if (SYSCALL(opcode))
	{
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno));
	  if (waitpid(g_pid, &status, 0) == -1)
	    return (display_error(errno));
	  if (!WIFEXITED(status))
	    {
	      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &call->regs) == -1)
		return (display_error(errno));
	      opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
	      main_printing(call);
	    }
	  else
	    printf("exit\n");
	}
      else
	{
	  /* if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1) */
	  /*   return (display_error(errno), 1); */
	  /* if (waitpid(g_pid, &status, 0) == -1) */
	  /*   return (display_error(errno), 1); */
	  /* if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1) */
	  /*   return (display_error(errno)); */
	  /* opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs); */
	  if (be_the_parent_rec(&status, call, &opcode, 0))
	    return 1;
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno), 1);
	  if (waitpid(g_pid, &status, 0) == -1)
	    return (display_error(errno), 1);
	  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	    return (display_error(errno));
	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
	}
    }
  return 0;
}
