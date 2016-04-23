/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Sat Apr 23 19:18:32 2016 florian videau
*/

#include <sys/user.h>
#include <stdio.h>
#include <string.h>
#include "../include/ftrace.h"
#include "../include/errnoent.h"

void	init_regs_tab(t_call *call)
{
  call->args_val[0] = call->regs.rdi;
  call->args_val[1] = call->regs.rsi;
  call->args_val[2] = call->regs.rdx;
  call->args_val[3] = call->regs.r10;
  call->args_val[4] = call->regs.r8;
  call->args_val[5] = call->regs.r9;
  call->args_val[6] = 0;
}

void		print_ret(t_call *call)
{
  int		i;
  t_types	type;

  type = g_syscalls[call->regs.orig_rax].ret;
  if (type == E_UNKN && printf("?"))
    return ;
  i = -1;
  if ((long)call->regs.rax >= 0)
    call->pr_type[type].ft_p(call->regs.rax, call);
  else
    while (g_errnoent[++i].nbr != -1)
      if (-(long)call->regs.rax == g_errnoent[i].nbr)
	printf("-1 %s (%s)", g_errnoent[i].name,
	      strerror(-(long)call->regs.rax));
}

int	print_syscall_name(int syscall)
{
  int	i;

  i = -1;
  while (strcmp(g_syscalls[++i].name, "") != 0)
    if (i == syscall)
      return (printf("%s", g_syscalls[syscall].name));
  return (printf("Unimplemented syscall : %d\n", syscall), 0);
}

int	print_arg_loop(t_call *call, int during)
{
  int	i;
  int	print_cur;

  i = -1;
  print_cur = 0;
  while (++i < during)
    {
      print_cur +=
	call->pr_type[g_syscalls[call->regs.orig_rax].args[i] - '0'].ft_p
	(call->args_val[i], call);
      if (i != during - 1)
	print_cur += printf(", ");
    }
  return (print_cur);
}

void		main_printing(t_call *call)
{
  int		print_cur;
  int		res;

  init_regs_tab(call);
  print_cur = PRINT_SPACE;
  if ((res = print_syscall_name((int)call->regs.orig_rax)) == 0)
    return ;
  print_cur -= res;
  print_cur -= printf("(");
  print_cur -= print_arg_loop(call,
			      strlen(g_syscalls[call->regs.orig_rax].args));
  print_cur -= printf(")");
  while (--print_cur > 0)
    printf(" ");
  printf(" = ");
  print_ret(call);
  printf("\n");
}
