/*
** dynamic_name_resolv.c for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun May 01 00:04:01 2016 Bastien DHIVER
** Last update Sun May 01 01:16:26 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "ftrace.h"

char	*is_addr_in_maps_lib(long_stuff addr, char *line)
{
  (void)addr;
  (void)line;
  return (NULL);
}

char		*dynamic_name_resolv(long_stuff addr)
{
  char		*path;
  FILE		*maps_file;
  char		*line;
  size_t	len;
  char		*ret;
  int		err;

  line = NULL;
  len = 0;
  ret = NULL;
  if (asprintf(&path, "/proc/%d/maps", g_pid) == -1)
    return (print_err("asprintf() failed: %s.\n", strerror(errno)), NULL);
  if ((maps_file = fopen(path, "r")) == NULL)
    return (print_err("fopen() failed: %s.\n", strerror(errno)), NULL);
  while ((err = getline(&line, &len, maps_file)) != -1)
    if ((ret = is_addr_in_maps_lib(addr, line)) != NULL)
      break;
  if (err == -1 && errno)
    print_err("getline() failed: %s.\n", strerror(errno));
  free(line);
  if (fclose(maps_file) == EOF)
    print_err("fclose() failed: %s.\n", strerror(errno));
  return (ret);
}

