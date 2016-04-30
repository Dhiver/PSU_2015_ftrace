/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Last update Sat Apr 30 23:57:03 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftrace.h"

int	be_the_child(t_args *args)
{
  int	fd;

  if ((fd = open("/dev/null", O_WRONLY)) == -1)
    return 1;
  if (dup2(fd, 1) == -1 || dup2(fd, 2) == -1)
    return 1;
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (execve(args->av[0], args->av, args->env) == -1)
    return (display_error(errno), 1);
  return (0);
}

int	one_more_step(int *status, t_call *call, unsigned long *opcode)
{
  if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (waitpid(g_pid, status, 0) == -1)
    return (display_error(errno), 1);
  if (aff_end_signal(*status))
    {
      if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
	return (display_error(errno), 1);
      if (!(*opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
	return (display_error(errno), 1);
      return 0;
    }
  return 1;
}

unsigned long	addr_relative(t_call *call, unsigned long opcode, char rexw)
{
  int		offset;
  unsigned long	call_addr;

  offset = (int)((opcode >> 8));
  if (rexw)
    {
      offset = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 1);
      call_addr = call->regs.rip + offset + 9;
    }
  else
    call_addr = call->regs.rip + offset + 5;
  return call_addr;
}

int	my_power_rec(int nbr, int power)
{
  return (power?nbr * my_power_rec(nbr, power -1):1);
}

unsigned long	*tab_no_sib_index(t_call *call)
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

unsigned long	*tab_yes_sib_index(t_call *call)
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

unsigned long	sib_index(t_call *call, t_rex *rex, unsigned long rmb)
{
  unsigned long	*tab;
  unsigned long addr;

  if (!rex->x)
    tab = tab_no_sib_index(call);
  else
    tab = tab_yes_sib_index(call);
  addr = tab[rmb];
  free(tab);
  return addr;
}

unsigned long	get_sib(unsigned char sib, t_call *call, t_rex *rex,
				char mod)
{
  char			scale;
  char			index;
  char			base;
  unsigned long		result;

  scale = sib & 0xC0;
  index = sib & 0x38;
  base = sib & 0x07;
  result = index >= 0 && index <= 7 ? sib_index(call, rex, index) : 0;
  result *= (scale > 0 && scale < 4?my_power_rec(2, scale):1);
  result += base >= 0 && base <= 7 ? sib_base(call, rex, base, mod) : 0;
  return (result);
}

unsigned long addr_indirect(unsigned long opcode, t_call *call, t_rex *rex)
{
  unsigned char	rmb;

  rmb = (opcode & 0xFF00) >> 8;
  if (rmb >= 0xD0 && rmb <= 0xD7)
      return D0rmbD7(call, rex, rmb);
  else if (rmb >= 0x10 && rmb <= 0x17)
    return l0rmb17(call, rex, rmb, opcode);
  else if (rmb >= 0x50 && rmb <= 0x57)
    return S0rmb57(call, rex, rmb, opcode);
  else if (rmb >= 0x90 && rmb <= 0x97)
    return J0rmb97(call, rex, rmb, opcode);
  return (0);
}

unsigned long	be_the_parent_rec(int *status, t_call *call, t_rex *rex, t_call_type calltype)
{
  unsigned long addr;
  unsigned long opcode;
  char		*fct_name;

  if (!(opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
    return (display_error(errno), 0);
  addr = (calltype == RELATIVE ? addr_relative(call, opcode, rex->w) :
	  addr_indirect(opcode, call, rex));
  fct_name = get_name_from_addr(addr);
  printf("Entering function %s at 0x%llx\n", fct_name, (long_stuff)addr);
  free(fct_name);
  if (one_more_step(status, call, &opcode))
    return 0;
  while(!RET(opcode) && aff_end_signal(*status))
    {
      bzero(rex, sizeof(t_rex));
      while (!CALL(opcode) && !RET(opcode) && (opcode & 0xF0) != 0x40 && !WIFEXITED(*status))
	if (one_more_step(status, call, &opcode))
	  return (0);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(status, call, &opcode))
	    return (0);
	  if (aff_end_signal(*status))
	      aff_syscall(call);
	  else
	    return (0);
	}
      if ((opcode & 0xF0) == 0x40)
      	{
      	  rex->w = opcode & 0x8;
      	  rex->r = opcode & 0x4;
      	  rex->x = opcode & 0x2;
      	  rex->b = opcode & 0x1;
      	  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, ++call->regs.rip);
      	}
      if (RET(opcode))
	{
	  fct_name = get_name_from_addr(addr);
	  printf("Leaving function %s\n", fct_name);
	  return (free(fct_name), opcode);
	}
      else if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(status, call, rex, RELATIVE)))
	    return 0;
	}
      else if (INDCALL(opcode))
	if (!(be_the_parent_rec(status, call, rex, INDIRECT)))
	  return 0;
      if (one_more_step(status, call, &opcode))
	return 0;
    }
  fct_name = get_name_from_addr(addr);
  printf("Leaving function %s\n", fct_name);
  return (free(fct_name), opcode);
}

int		be_the_parent(t_call *call, char *pathname)
{
  int		status;
  unsigned long	opcode;
  t_rex		rex;

  if (load_elf(pathname))
    return (1);
  if (gelf_getclass(g_bin.e) == ELFCLASS32)
    {
#define ELF_IS_32_
    }
  else
    {
#undef ELF_IS_32_
    }
  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno), 1);
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &(call->regs)) == -1)
    return (display_error(errno));
  opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs);
  while (aff_end_signal(status))
    {
      bzero(&rex, sizeof(t_rex));
      while (!opcode || !CALL(opcode))
	if (one_more_step(&status, call, &opcode))
	  return (1);
      if (SYSCALL(opcode))
	{
	  if (one_more_step(&status, call, &opcode))
	    return (1);
	  if (aff_end_signal(status))
	    aff_syscall(call);
	}
      if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, RELATIVE)))
	    return 1;
	}
      else if (INDCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, INDIRECT)))
	    return 1;
	}
      if (one_more_step(&status, call, &opcode))
	return (1);
    }
  return (0);
}
