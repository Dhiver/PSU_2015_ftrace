/*
** ftrace.h for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 14:07:13 2016 florian videau
** Last update Sun May 01 03:05:51 2016 Bastien DHIVER
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# define _GNU_SOURCE
# include <gelf.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/user.h>

# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"
# define SIGNAL_RCV_MSG		"Received signal %s\n"
# define SIGNAL_UNKN		"UNKNOWN"

# define print_err(...)		fprintf(stderr, __VA_ARGS__)

# define SYSCALL(opcode)        ((opcode & 0x0000FFFF) == 0x0000050f)
# define RELCALL(opcode)	((opcode & 0xFF) == 0xe8)
# define INDCALL(opcode)	((opcode & 0xFF) == 0xFF && (opcode & 0x3800) == 0x1000)

# define CALL(opcode)		(SYSCALL(opcode) || RELCALL(opcode) || INDCALL(opcode))

# define RET(opcode)		((opcode & 0xFF) == 0xC3 || (opcode & 0xFF) == 0xC2  || (opcode & 0xFF) == 0xCA  || (opcode & 0xFF) == 0xCB)

typedef enum			e_call_type
  {
    RELATIVE,
    INDIRECT
  }				t_call_type;

typedef	enum			e_bool
{
  FALSE,
  TRUE
}				t_bool;

typedef struct			s_bin_infos
{
  char				*name;
  int				fd;
  Elf				*e;
}				t_bin_infos;

extern pid_t			g_pid;
extern t_bin_infos		g_bin;

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

typedef struct			s_call
{
  t_regs			regs;
  long_stuff			args_val[7];
}				t_call;

typedef struct			s_rex
{
  char				w;
  char				r;
  char				x;
  char				b;
}				t_rex;

/*
** find_executable.c
*/
char				*find_executable(char *name);

/*
** trace.c
*/
int				be_the_child(t_args *arg);
int				be_the_parent(t_call *call, char *);

/*
** utils.c
*/
int				display_error(int);

/*
** signals.c
*/
void				get_sigint(int);
int				aff_end(int);

/*
** load_elf.c
*/
int				load_elf(char *, t_bin_infos *);
int				unload_elf(t_bin_infos *);

/*
** get_name_from_addr.c
*/
char				*get_name_from_addr(long_stuff);

/*
** print_syscalls.c
*/
void				aff_syscall(t_call *);

/*
** print_signals.c
*/
int				aff_end_signal(int);

/*
** static_name_resolv.c
*/
char				*static_name_resolv(long_stuff);

/*
** dynamic_name_resolv.c
*/
char				*dynamic_name_resolv(long_stuff);

unsigned long	get_sib(unsigned char sib, t_call *call, t_rex *rex,
				char mod);
unsigned long	J0rmb97(t_call *call, t_rex *rex, unsigned long rmb, unsigned long opcode);

unsigned long	S0rmb57(t_call *call, t_rex *rex, unsigned long rmb, unsigned long opcode);

unsigned long	l0rmb17(t_call *call, t_rex *rex, unsigned long rmb, unsigned long opcode);

unsigned long	D0rmbD7(t_call *call, t_rex *rex, unsigned long rmb);

unsigned long	sib_base(t_call *call, t_rex *rex, unsigned long rmb, char mod);

#endif /* !FTRACE_H_ */
