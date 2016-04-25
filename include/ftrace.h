/*
** ftrace.h for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 14:07:13 2016 florian videau
** Last update Sun Apr 24 17:51:29 2016 florian videau
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include <stdio.h>
# include <sys/types.h>
# include <sys/user.h>
# include "syscalls.h"

# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"
# define PRINT_SPACE		(40)
# define MAX_PRINT_CHAR		(32)
# define MAX_PRINT_SPEC		(62)

# define print_err(...)		fprintf(stderr, __VA_ARGS__)

# define SYSCALL(opcode)        ((opcode & 0x0000FFFF) == 0x0000050f)
# define RELCALL(opcode)	((opcode & 0xFF) == 0xe8)
# define INDCALL(opcode)	((opcode & 0xFF) == 0xFF && (opcode & 0x3800) == 0x1000)

# define CALL(opcode)		(SYSCALL(opcode) || RELCALL(opcode) || INDCALL(opcode))

# define RET(opcode)		((opcode & 0xFF0000) == 0xC30000)

typedef	enum			e_bool
{
  FALSE,
  TRUE
}				t_bool;

extern pid_t			g_pid;

typedef	struct user_regs_struct	t_regs;

typedef unsigned long long int	long_stuff;

typedef	struct			s_args
{
  char				**av;
  char				**env;
}				t_args;

typedef struct			s_pr_type
{
  int				(*ft_p)(long_stuff, void *);
}				t_pr_type;

typedef struct                  s_call
{
  t_pr_type                     pr_type[E_END + 1];
  t_regs                        regs;
  long_stuff                    args_val[7];
  t_bool                        is_child;
} t_call;

/*
**find_executable.c
*/
char				*find_executable(char *name);

/*
** print_fct.c
*/
int				print_unkn(long_stuff, void *);
int				print_int(long_stuff, void *);
int				print_str(long_stuff, void *);
int				print_addr(long_stuff, void *);
int				print_struc(long_stuff, void *);

/*
** print_fct_again.c
*/
int				print_size_t(long_stuff, void *);
int				print_two_int(long_stuff, void *);
int				print_usi_l(long_stuff, void *);
int				print_strstr(long_stuff, void *);
int				print_long(long_stuff, void *);

/*
**trace.c
*/
int				be_the_child(t_args *arg);
int				be_the_parent(t_call *call);

/*
** utils.c
*/
int				display_error(int);

/*
** signals.c
*/
void				get_sigint(int);
int				aff_end(int);


void				main_printing(t_call *);
#endif /*FTRACE_H_*/
