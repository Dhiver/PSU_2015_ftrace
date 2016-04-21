/*
** test.c for tpftrace in /home/videau_f/rendu/PSU/tpftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Mon Apr 11 09:21:28 2016 florian videau
** Last update Mon Apr 11 09:23:28 2016 florian videau
*/

#include <stdio.h>
#include <stdlib.h>

void	toto(void)
{
  printf("je suis dans toto()\n");
}

void	tutu(void)
{
  printf("je suis dans tutu()\n");
}

int	main(void)
{
  toto();
  tutu();
  exit(0);
}
