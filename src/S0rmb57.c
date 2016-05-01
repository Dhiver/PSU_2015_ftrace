/*
** S0rmb57.c for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Sat Apr 30 18:39:03 2016 florian videau
** Last update Sun May 01 09:20:56 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <sys/ptrace.h>
#include "ftrace.h"

unsigned long	*tab_no_S0rmb57(t_call *call, t_rex *rex,
				unsigned long addr, unsigned long opcode)
{
  unsigned long	*tab;

  tab = malloc(8 * sizeof(long));
  tab[0] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rax + addr);
  tab[1] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rcx + addr);
  tab[2] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdx + addr);
  tab[3] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbx);
  tab[4] = ptrace(PTRACE_PEEKTEXT, g_pid,
		  get_sib((opcode & 0xFF0000) >> 16, call, rex, 1) + addr);
  tab[5] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbp + addr);
  tab[6] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rsi + addr);
  tab[7] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdi + addr);
  return (tab);
}

unsigned long	*tab_yes_S0rmb57(t_call *call, t_rex *rex,
				 unsigned long addr, unsigned long opcode)
{
  unsigned long	*tab;

  tab = malloc(8 * sizeof(long));
  tab[0] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r8 + addr);
  tab[1] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r9 + addr);
  tab[2] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r10 + addr);
  tab[3] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r11 + addr);
  tab[4] = ptrace(PTRACE_PEEKTEXT, g_pid,
		  get_sib((opcode & 0xFF0000) >> 16, call, rex, 1) + addr);
  tab[5] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r13 + addr);
  tab[6] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r14 + addr);
  tab[7] = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r15 + addr);
  return (tab);
}

unsigned long	S0rmb57(t_call *call, t_rex *rex,
			unsigned long rmb, unsigned long opcode)
{
  unsigned long	*tab;
  unsigned long addr;

  if (!rex->b)
    tab = tab_no_S0rmb57(call, rex, (opcode & 0xFF0000) >> 16, opcode);
  else
    tab = tab_yes_S0rmb57(call, rex, (opcode & 0xFF0000) >> 16, opcode);
  addr = tab[rmb & 0x0F];
  free(tab);
  return (addr);
}
