/*
** print_signals.c for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Apr 20 10:53:11 2016 Bastien DHIVER
** Last update Wed Apr 20 10:57:47 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include "ftrace.h"
#include "signals.h"

void	print_si_code(int signo, int code)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  if (code == SI_KERNEL)
    print_err("si_code=SI_KERNEL, ");
  else if (code <= 0)
    {
      while (g_si_code[++i].nbr != -1)
	if (g_si_code[i].nbr == code)
	  print_err("si_code=%s, ", g_si_code[i].name);
    }
  else
    while (g_sig_groups[++i].idx != -1)
      if (g_sig_groups[i].idx == signo)
	while (g_sig_groups[i].group_name[++j].nbr != -1)
	  if (g_sig_groups[i].group_name[j].nbr == code)
	    {
	      print_err("si_code=%s, ", g_sig_groups[i].group_name[j].name);
	      return ;
	    }
}

void	print_si_extra(siginfo_t *info)
{
  if (info->si_code > 0)
    print_err("si_addr=%p", info->si_addr);
  else
    print_err("si_pid=%d, si_uid=%d", info->si_pid, info->si_uid);
  print_err("} ---\n+++ killed by ");
}

void	aff_signal(siginfo_t *info)
{
  int	i;

  i = -1;
  while (g_signals[++i].nbr != -1)
    if (g_signals[i].nbr == info->si_signo)
      {
	print_err("%s {si_signo=%s, ", g_signals[i].name, g_signals[i].name);
	break;
      }
  print_si_code(info->si_signo, info->si_code);
  print_si_extra(info);
  print_err("%s +++\n", g_signals[i].name);
  kill(g_pid, info->si_signo);
}

