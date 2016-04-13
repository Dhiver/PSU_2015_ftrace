/*
** ftrace.c for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace/src
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 11:59:11 2016 florian videau
** Last update Wed Apr 13 11:02:46 2016 florian videau
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ftrace.h"

int	run_process(t_args *args)
{
  char	*file_w_path;
  int	pid;

  if ((file_w_path = find_executable(args->av[0])) == NULL)
    return (fprintf(stderr, "Can't find or execute '%s'\n", args->av[0]), 1);
  if ((pid = fork()) == 1)
    return (fprintf(stderr, "%s\n", strerror(errno)), -1);
  if (!pid)
    return (be_the_child(args));
  else
    return (be_the_parent(pid));
  return 0;
}

int		main(int ac, char **av, char **env)
{
  t_args	args;

  if (ac < 2)
    return (fprintf(stderr, "Usage : %s <command>", av[0]), 0);
  args.av = av + 1;
  args.env = env;
  return (run_process(&args));
}
