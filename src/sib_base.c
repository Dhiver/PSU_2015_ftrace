/*
** sib_base.c for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Sat Apr 30 18:56:58 2016 florian videau
** Last update Sat Apr 30 18:57:51 2016 florian videau
*/

#include <stdlib.h>
#include <sys/ptrace.h>
#include "../include/ftrace.h"


unsigned long	*tab_yes_sib_base(t_call *call)
{
  unsigned long	*tab;

  tab = malloc(8 * sizeof(long));

  tab[0] = call->regs.r8;
  tab[1] = call->regs.r9;
  tab[2] = call->regs.r10;
  tab[3] = call->regs.r11;
  tab[4] = call->regs.r12;
  tab[5] = call->regs.r13;
  tab[6] = call->regs.r14;
  tab[7] = call->regs.r15;
  return tab;
}

unsigned long	*tab_no_b_sib_base(t_call *call)
{
  unsigned long	*tab;

  tab = malloc(8 * sizeof(long));

  tab[0] = call->regs.rax;
  tab[1] = call->regs.rcx;
  tab[2] = call->regs.rdx;
  tab[3] = call->regs.rbx;
  tab[4] = call->regs.rsp;
  tab[5] = call->regs.rbp;
  tab[6] = call->regs.rsi;
  tab[7] = call->regs.rdi;
  return tab;
}

unsigned long	*tab_no_sib_base(t_call *call)
{
  unsigned long	*tab;

  tab = malloc(8 * sizeof(long));

  tab[0] = call->regs.rax;
  tab[1] = call->regs.rcx;
  tab[2] = call->regs.rdx;
  tab[3] = call->regs.rbx;
  tab[4] = call->regs.rsp;
  tab[5] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 3) & 0xFFFFFFFF;
  tab[6] = call->regs.rsi;
  tab[7] = call->regs.rdi;
  return tab;
}

unsigned long	sib_base(t_call *call, t_rex *rex, unsigned long rmb, char mod)
{
  unsigned long	*tab;
  unsigned long addr;

  if (rex->b && mod)
    tab = tab_yes_sib_base(call);
  else if (mod)
    tab = tab_no_b_sib_base(call);
  else
    tab = tab_no_sib_base(call);
  addr = tab[rmb];
  free(tab);
  return addr;
}