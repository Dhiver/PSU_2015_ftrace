/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Sun Apr 24 09:35:23 2016 florian videau
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

int		inspect_regs(int pid)
{
  t_regs	regs;

  if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
    return (display_error(errno), 1);
  /* if ((long long)call->regs.orig_rax != -1) */
  /*   main_printing(call); */
  printf("I see orig_rax : %d, rax : %d\n", (int)regs.orig_rax, (int)regs.rax);
  return (0);
}

int	be_the_parent_rec(int status, t_call *call, unsigned long opcode, int indent)
{
  int	i;

  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Entering function : %s at %llx\n", "toto", (unsigned long long) call->regs.rip);
  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while(!RET(opcode))
    {
      i = 0;
      while (!CALL(opcode) && !RET(opcode))
  	{
  	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
  	    return (display_error(errno), 1);
  	  if (waitpid(g_pid, &status, 0) == -1)
  	    return (display_error(errno), 1);
	  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	    return (display_error(errno));
	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  	}
      if (RET(opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("Leaving function %s\n", "toto");
	  return 0;
	}
      if (SYSCALL(opcode))
	{
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno));
	  if (waitpid(g_pid, &status, 0) == -1)
	    return (display_error(errno));
	  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &call->regs) == -1)
	    return (display_error(errno));
	  main_printing(call);
	}
      if (RELCALL(opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("RELATIVE\n");
	  be_the_parent_rec(status, call, opcode, indent + 1);
	}
      else if (INDCALL(opcode))
	{
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("INDIRECT\n");
	  be_the_parent_rec(status, call, opcode, indent + 1);
	}
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno), 1);
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno), 1);
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno));
      opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
    }
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Leaving function %s\n", "toto");
  return (0);
  /* while (1) */
  /*   { */
  /*     if (!aff_end(status)) */
  /* 	return (0); */
  /*     if (inspect_regs(pid)) */
  /* 	return (1); */
  /*     if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1) */
  /* 	return (display_error(errno), 1); */
  /*     if (waitpid(pid, &status, 0) == -1) */
  /* 	return (display_error(errno), 1); */
  /*   } */
  return 0;
}

int	be_the_parent(t_call *call)
{
  int		status;
  unsigned long	opcode;

  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (!CALL(opcode))
    {
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno), 1);
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno), 1);
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno));
      opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
    }
  return (be_the_parent_rec(status, call, opcode, 0));
}
