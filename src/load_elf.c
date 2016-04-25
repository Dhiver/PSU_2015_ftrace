/*
** load_elf.c for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Mon Apr 25 23:00:21 2016 Bastien DHIVER
** Last update Mon Apr 25 23:36:15 2016 Bastien DHIVER
*/

#include <err.h>
#include <gelf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ftrace.h"

int	load_elf(char *pathname)
{
  g_bin.name = pathname;
  if (elf_version(EV_CURRENT) == EV_NONE)
    errx(EXIT_FAILURE, "ELF lib initialisation failed: %s.", elf_errmsg(-1));
  if ((g_bin.fd = open(g_bin.name, O_RDONLY)) == -1)
    errx(EXIT_FAILURE, "open %s failed: %s.", g_bin.name, strerror(errno));
  if ((g_bin.e = elf_begin(g_bin.fd, ELF_C_READ, NULL)) == NULL)
    errx(EXIT_FAILURE, "elf_begin() failed: %s.", elf_errmsg(-1));
  if (elf_kind(g_bin.e) != ELF_K_ELF)
    errx(EXIT_FAILURE, "%s is not an ELF object.", g_bin.name);
  if (gelf_getclass(g_bin.e) == ELFCLASSNONE)
    errx(EXIT_FAILURE, "getclass() failed: %s.", elf_errmsg(-1));
  return (EXIT_SUCCESS);
}

int	unload_elf(void)
{
  if (elf_end(g_bin.e) == -1)
    errx(EXIT_FAILURE, "elf_end() failed: %s.", elf_errmsg(-1));
  if (close(g_bin.fd) == -1)
    errx(EXIT_FAILURE, "close() %s failed: %s.", g_bin.name, strerror(errno));
  return (EXIT_SUCCESS);
}
