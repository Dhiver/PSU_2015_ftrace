/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Thu Apr 21 15:20:00 2016 florian videau
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

int	be_the_parent_rec(int status)
{

  printf("Entering function : %s at %llx\n", "toto", (unsigned long long) 42);
  while(/*pas de ret*/)
    {
      while (/*pas de call ni de ret*/)
	{
	  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	    return (display_error(errno), 1);
	  if (waitpid(g_pid, &status, 0) == -1)
	    return (display_error(errno), 1);
	}
      if (/*un call*/)
	be_the_parent_rec(status);
    }
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
}

int	be_the_parent(void)
{
  int	status;

  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  while (/*pas de call*/)
    {
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno), 1);
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno), 1);
    }
  return (be_the_parent_rec(status));
}
