/*
** signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Apr 02 22:31:08 2016 Bastien DHIVER
** Last update Wed Apr 20 12:21:29 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include "ftrace.h"

void	get_sigint(int sig)
{
  (void)sig;
  kill(g_pid, SIGKILL);
  print_err("Process %d detached\n", g_pid);
  print_err(" <detached ...>\n");
  exit(0);
}

int		aff_end(int status)
{
  siginfo_t	info;

  if (WIFEXITED(status))
    {
      if (!(WSTOPSIG(status) == SIGSEGV))
	print_err("+++ exited with %d +++\n", WSTOPSIG(status));
      return (0);
    }
  else if (WIFSTOPPED(status))
    {
      if (ptrace(PTRACE_GETSIGINFO, g_pid, NULL, &info))
	return (display_error(errno), 1);
      if (info.si_signo != SIGTRAP && info.si_signo != SIGSTOP)
	return (print_err("--- "), aff_signal(&info), 0);
    }
  return (1);
}

