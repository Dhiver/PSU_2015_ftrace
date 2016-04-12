/*
** ftrace.c for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace/src
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 11:59:11 2016 florian videau
** Last update Tue Apr 12 15:10:11 2016 florian videau
*/

#include <stdio.h>
#include "ftrace.h"

int	run_process(char *file)
{
  char	*file_w_path;

  if ((file_w_path = find_executable(file)) == NULL)
    return (fprintf(stderr, "Can't find or execute '%s'\n", file), 1);
  return 0;
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (fprintf(stderr, "Usage : %s <command>", av[0]), 0);
  return (run_process(av[1]));
}
