/*
** print_fct.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Tue Apr 05 21:11:06 2016 Bastien DHIVER
** Last update Sat Apr 23 19:31:43 2016 florian videau
*/

#include "../include/ftrace.h"

int	print_unkn(long_stuff value, void *call)
{
  (void)value;
  (void)call;
  return (0);
}

int	print_int(long_stuff value, void *call)
{
  (void)call;
  return (printf("%d", (int)value));
}

int	print_addr(long_stuff value, void *call_addr)
{
  (void)call_addr;
  if (!value)
    return (printf("NULL"));
  return (printf("0x%llx", value));
}

int	print_struc(long_stuff value, void *call_addr)
{
  (void)call_addr;
  return (printf("{0x%llx}", value));
}
