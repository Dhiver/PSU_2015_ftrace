/*
** signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Sat Apr 02 22:31:08 2016 Bastien DHIVER
** Last update Thu Apr 21 10:26:39 2016 florian videau
*/

#define _GNU_SOURCE
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
