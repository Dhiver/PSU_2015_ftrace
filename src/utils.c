/*
** utils.c for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:18:13 2016 Bastien DHIVER
** Last update Thu Apr 21 10:09:24 2016 florian videau
*/

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include "ftrace.h"

int	display_error(int errsav)
{
  return (print_err("%s\n", strerror(errsav)), 1);
}

int	get_nbr(char *str, long int *nbr)
{
  char	*tmp;

  if (!str || *str == '\0')
    return (1);
  *nbr = strtol(str, &tmp, 10);
  return ((*nbr == LONG_MIN || *nbr == LONG_MAX || *tmp != '\0') ? 1 : 0);
}
