/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
 **
** Last update Fri Apr 29 13:41:43 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ftrace.h"

int	be_the_child(t_args *args)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno), 1);
  if (execve(args->av[0], args->av, args->env) == -1)
    return (display_error(errno), 1);
  return (1);
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
      printf("BITE\n");
      offset = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 1);
      call_addr = call->regs.rip + offset + 9;
    }
  else
    {
      /* int val; */
      /* val = offset & 0xFFFFFF; */
      call_addr = call->regs.rip + offset + 5;
    }
  return call_addr;
}

static unsigned long	get_sib(unsigned char sib, t_call *call, t_rex *rex,
				char mod, int pid)
{
  char			scale, index, base;
  unsigned long		result = 0;

  scale = sib & 0xC0;
  index = sib & 0x38;
  base = sib & 0x07;
  switch (index)
    {
    case 0:
	if (rex->x)
	  result += call->regs.r8;
	else
	  result += call->regs.rax;
      break;
    case 1:
      if (rex->x)
	result += call->regs.r9;
      else
	result += call->regs.rcx;
      break;
    case 2:
      if (rex->x)
	result += call->regs.r10;
      else
	result += call->regs.rdx;
      break;
    case 3:
      if (rex->x)
	result += call->regs.r11;
      else
	result += call->regs.rbx;
      break;
    case 4:
      if (rex->x)
	result += call->regs.r12;
      break;
    case 5:
      if (rex->x)
	result += call->regs.r13;
      else
	result += call->regs.rbp;
      break;
    case 6:
      if (rex->x)
	result += call->regs.r14;
      else
	result += call->regs.rsi;
      break;
    case 7:
      if (rex->x)
	result += call->regs.r15;
      else
	result += call->regs.rdi;
      break;
    }
  switch (scale)
    {
    case 0:
      break;
    case 1:
      result *= 2;
      break;
    case 2:
      result *= 4;
      break;
    case 3:
      result *= 8;
      break;
    }
  switch (base)
    {
    case 0:
      if (rex->b)
	result += call->regs.r8;
      else
	result += call->regs.rax;
      break;
    case 1:
      if (rex->b)
	result += call->regs.r9;
      else
	result += call->regs.rcx;
      break;
    case 2:
      if (rex->b)
	result += call->regs.r10;
      else
	result += call->regs.rdx;
      break;
    case 3:
      if (rex->b)
	result += call->regs.r11;
      else
	result += call->regs.rbx;
      break;
    case 4:
      if (rex->b)
	result += call->regs.r12;
      else
	result += call->regs.rsp;
      break;
    case 5:
      if (rex->b && mod)
	result += call->regs.r13;
      else if (mod)
	result += call->regs.rbp;
      else
	result += ptrace(PTRACE_PEEKTEXT, pid, call->regs.rip + 3) & 0xFFFFFFFF;
      break;
    case 6:
      if (rex->b)
	result += call->regs.r14;
      else
	result += call->regs.rsi;
      break;
    case 7:
      if (rex->b)
	result += call->regs.r15;
      else
	result += call->regs.rdi;
      break;
    }
  return (result);
}

unsigned long addr_indirect(unsigned long opcode, t_call *call, t_rex *rex)
{
  unsigned char	rmb;
  unsigned long	addr;
  unsigned long addb;

  addr = opcode;
  rmb = (opcode & 0xFF00) >> 8;
  if (rmb >= 0xD0 && rmb <= 0xD7)
    {
      if (!rex->b && rmb == 0xD0)
	addr = call->regs.rax;
      else if (!rex->b && rmb == 0xD1)
	addr = call->regs.rcx;
      else if (!rex->b && rmb == 0xD2)
	addr = call->regs.rdx;
      else if (!rex->b && rmb == 0xD3)
	addr = call->regs.rbx;
      else if (!rex->b && rmb == 0xD4)
	addr = call->regs.rsp;
      else if (!rex->b && rmb == 0xD5)
	addr = call->regs.rbp;
      else if (!rex->b && rmb == 0xD6)
	addr = call->regs.rsi;
      else if (!rex->b && rmb == 0xD7)
	addr = call->regs.rdi;
      else if (rex->b && rmb == 0xD0)
	addr = call->regs.r8;
      else if (rex->b && rmb == 0xD1)
	addr = call->regs.r9;
      else if (rex->b && rmb == 0xD2)
	addr = call->regs.r10;
      else if (rex->b && rmb == 0xD3)
	addr = call->regs.r11;
      else if (rex->b && rmb == 0xD4)
	addr = call->regs.r12;
      else if (rex->b && rmb == 0xD5)
	addr = call->regs.r13;
      else if (rex->b && rmb == 0xD6)
	addr = call->regs.r14;
      else if (rex->b && rmb == 0xD7)
	addr = call->regs.r15;
    }
  else if (rmb >= 0x10 && rmb <= 0x17)
    {
      if (!rex->b && rmb == 0x10)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rax);
      else if (!rex->b && rmb == 0x11)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rcx);
      else if (!rex->b && rmb == 0x12)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdx);
      else if (!rex->b && rmb == 0x13)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbx);
      else if (rmb == 0x14)
	{
	  addr = ptrace(PTRACE_PEEKTEXT, g_pid, get_sib((opcode & 0xFF0000) >> 16, call, rex, 0, g_pid));
	}
      else if (rmb == 0x15)
	{
	  addb = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 2) & 0xFFFFFFFF;
	  addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 6 + addb);
	}
      else if (!rex->b && rmb == 0x16)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rsi);
      else if (!rex->b && rmb == 0x17)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdi);
      else if (rex->b && rmb == 0x10)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r8);
      else if (rex->b && rmb == 0x11)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r9);
      else if (rex->b && rmb == 0x12)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r10);
      else if (rex->b && rmb == 0x13)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r11);
      else if (rex->b && rmb == 0x16)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r14);
      else if (rex->b && rmb == 0x17)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r15);
    }
  else if (rmb >= 0x50 && rmb <= 0x57)
    {
      addb = (opcode & 0xFF0000) >> 16;
      if (!rex->b && rmb == 0x50)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rax + addb);
      else if (!rex->b && rmb == 0x51)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rcx + addb);
      else if (!rex->b && rmb == 0x52)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdx + addb);
      else if (!rex->b && rmb == 0x53)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbx + addb);
      else if (rmb == 0x54)
	{
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, get_sib((opcode & 0xFF0000) >> 16, call, rex, 1, g_pid) + addb);
	}
      else if (!rex->b && rmb == 0x55)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbp + addb);
      else if (!rex->b && rmb == 0x56)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rsi + addb);
      else if (!rex->b && rmb == 0x57)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdi + addb);
      else if (rex->b && rmb == 0x50)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r8 + addb);
      else if (rex->b && rmb == 0x51)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r9 + addb);
      else if (rex->b && rmb == 0x52)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r10 + addb);
      else if (rex->b && rmb == 0x53)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r11 + addb);
      else if (rex->b && rmb == 0x55)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r13 + addb);
      else if (rex->b && rmb == 0x56)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r14 + addb);
      else if (rex->b && rmb == 0x57)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r15 + addb);
    }
  else if (rmb >= 0x90 && rmb <= 0x97)
    {
      addb = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip + 2) & 0xFFFFFFFF;
      if (!rex->b && rmb == 0x90)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rax + addb);
      else if (!rex->b && rmb == 0x91)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rcx + addb);
      else if (!rex->b && rmb == 0x92)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdx + addb);
      else if (!rex->b && rmb == 0x93)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbx + addb);
      else if (rmb == 0x94)
	{
	  addr = ptrace(PTRACE_PEEKTEXT, g_pid, get_sib((opcode & 0xFF0000) >> 16, call, rex, 2, g_pid) + addb);
	}
      else if (!rex->b && rmb == 0x95)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rbp + addb);
      else if (!rex->b && rmb == 0x96)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rsi + addb);
      else if (!rex->b && rmb == 0x97)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rdi + addb);
      else if (rex->b && rmb == 0x90)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r8 + addb);
      else if (rex->b && rmb == 0x91)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r9 + addb);
      else if (rex->b && rmb == 0x92)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r10 + addb);
      else if (rex->b && rmb == 0x93)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r11 + addb);
      else if (rex->b && rmb == 0x95)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r13 + addb);
      else if (rex->b && rmb == 0x96)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r14 + addb);
      else if (rex->b && rmb == 0x97)
	addr = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.r15 + addb);
    }
  return (addr);
}

unsigned long	be_the_parent_rec(int *status, t_call *call, t_rex *rex, int indent, t_call_type calltype)
{
  int		i;
  unsigned long addr;
  unsigned long opcode;

  if (!(opcode = ptrace(PTRACE_PEEKTEXT, g_pid, call->regs.rip, call->regs)))
    return (display_error(errno), 0);
  addr = (calltype == RELATIVE ? addr_relative(call, opcode, rex->w) :
	  addr_indirect(opcode, call, rex));
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Entering function ");
  get_name_from_addr(addr);
  printf(" : at 0x%llx\n", (unsigned long long) addr);
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
	    {
	      i = -1;
	      while (++i < indent)
		printf(" ");
	      aff_syscall(call);
	    }
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
	  i = -1;
	  while (++i < indent)
	    printf(" ");
	  printf("Leaving function\n");
	  return opcode;
	}
      else if (RELCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(status, call, rex, indent + 1, RELATIVE)))
	    return 0;
	}
      else if (INDCALL(opcode))
	{
	  if (!(be_the_parent_rec(status, call, rex, indent + 1, INDIRECT)))
	    return 0;
	}
      if (one_more_step(status, call, &opcode))
	return 0;
    }
  i = -1;
  while (++i < indent)
    printf(" ");
  printf("Leaving function\n");
  return (opcode);
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
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, 0, RELATIVE)))
	    return 1;
	}
      else if (INDCALL(opcode))
	{
	  if (!(opcode = be_the_parent_rec(&status, call, &rex, 0, INDIRECT)))
	    return 1;
	}
      if (one_more_step(&status, call, &opcode))
	return (1);
    }
  return (0);
}
