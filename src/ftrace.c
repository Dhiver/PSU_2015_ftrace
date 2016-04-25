/*
** ftrace.c for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace/src
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 11:59:11 2016 florian videau
** Last update Mon Apr 25 23:34:00 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "../include/ftrace.h"

pid_t		g_pid = 0;
t_bin_infos	g_bin;

void	init_pr_type(t_pr_type *tab)
{
  tab[E_UNKN].ft_p = &print_unkn;
  tab[E_INT].ft_p = &print_int;
  tab[E_STR].ft_p = &print_str;
  tab[E_ADDR].ft_p = &print_addr;
  tab[E_STRUC].ft_p = &print_struc;
  tab[E_SIZE_T].ft_p = &print_size_t;
  tab[E_INT_2].ft_p = &print_two_int;
  tab[E_USI_L].ft_p = &print_usi_l;
  tab[E_STRSTR].ft_p = &print_strstr;
  tab[E_LONG].ft_p = &print_long;
  tab[E_END].ft_p = NULL;
}

int	run_process(t_args *args, t_call *call)
{
  char	*file_w_path;

  if ((file_w_path = find_executable(args->av[0])) == NULL)
    return (print_err("Can't find or execute '%s'\n", args->av[0]), 1);
  args->av[0] = file_w_path;
  if ((g_pid = fork()) == -1)
    return (display_error(errno), 1);
  return ((!g_pid) ? be_the_child(args) : be_the_parent(call, args->av[0]));
}

int		main(int ac, char **av, char **env)
{
  t_args	args;
  t_call	call;

  if (ac < 2)
    return (print_err("Usage : %s <command>\n", av[0]), 0);
  signal(SIGINT, &get_sigint);
  args.av = av + 1;
  args.env = env;
  call.is_child = TRUE;
  init_pr_type(call.pr_type);
  return (run_process(&args, &call));
}
