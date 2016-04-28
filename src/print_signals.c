/*
** print_signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Sun Apr 10 12:23:38 2016 Bastien DHIVER
** Last update Thu Apr 28 21:23:02 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "ftrace.h"

char	*signal_name(int signo)
{
  char	*name;

  return ((name = strsignal(signo)) ? name : SIGNAL_UNKN);
}

int	aff_end_signal(int status)
{
  if (WIFEXITED(status))
    return (printf("+++ exited with %d +++\n", WEXITSTATUS(status)), 0);
  else if (WIFSIGNALED(status))
    return (printf(SIGNAL_RCV_MSG, signal_name(WTERMSIG(status))), 0);
  else if (WIFSTOPPED(status))
      if (WSTOPSIG(status) != SIGTRAP && WSTOPSIG(status) != SIGSTOP)
	return (printf(SIGNAL_RCV_MSG, signal_name(WTERMSIG(status))), 0);
  return (1);
}
