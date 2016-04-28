/*
** get_name_from_addr.c for ftrace in /home/work/work/projects/PSU_2015_ftrace_doc/PSU_2015_ftrace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Wed Apr 20 14:27:12 2016 Bastien DHIVER
** Last update Thu Apr 28 16:54:34 2016 florian videau
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <strings.h>
#include <dlfcn.h>
#include "ftrace.h"

/*
** Return 1 if symbol is a static function
*/
int	sym_is_static(GElf_Sym *sym)
{
  return ((GELF_ST_TYPE(sym->st_info) == STT_FUNC) &&
	  (sym->st_shndx != SHT_NULL));
}

/*
** Return 1 if symbol is associated with a function
*/
int	sym_is_dynamic(GElf_Sym *sym)
{
  return ((GELF_ST_TYPE(sym->st_info) == STT_FUNC));
}

int		get_name_from_addr(long_stuff addr)
{
  GElf_Shdr	shdr;
  Elf_Scn	*scn;
  Elf_Data	*data;
  GElf_Sym	sym;
  int		count;
  int		i;
  Dl_info	info;
  char		*err;

  (void)addr;
  scn = NULL;
  while ((scn = elf_nextscn(g_bin.e, scn)) != NULL)
    {
      if (gelf_getshdr(scn, &shdr) != &shdr)
	return (print_err("gelf_getshdr() failed: %s.", elf_errmsg(-1)), 1);
      if (shdr.sh_type == SHT_SYMTAB)
	{
	  if ((data = elf_getdata(scn, NULL)) == NULL)
	    return (print_err("elf_getdata() failed: %s.",
			      elf_errmsg(-1)), 1);
	  count = shdr.sh_size / shdr.sh_entsize;
	  i = -1;
	  while (++i < count)
	    {
	      if (gelf_getsym(data, i, &sym) == NULL)
		return (print_err("gelf_getsym() failed: %s.",
				  elf_errmsg(-1)), 1);
	      if ((!sym.st_name) || sym.st_value == 0)
		continue;
	      else if ((long_stuff)sym.st_value == (long_stuff)addr)
		return (printf("%s", elf_strptr(g_bin.e, shdr.sh_link, sym.st_name)), 0);
	    }
	}
    }
  if (!dladdr((void *)addr, &info) && (err = dlerror()))
    return (print_err("dladdr() failed: %s.\n", err), 1);
  if (info.dli_sname && info.dli_saddr && info.dli_saddr == (void *)addr)
    return (printf("Symbol name is '%s' in the shared lib '%s'\n", info.dli_sname, info.dli_fname), 0);
  return (printf("func_0x%llX@%s", (long_stuff)addr, rindex(g_bin.name, '/') + 1), 0);
}
