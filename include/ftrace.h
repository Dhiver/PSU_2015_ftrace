/*
** ftrace.h for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 14:07:13 2016 florian videau
** Last update Wed Apr 20 12:20:05 2016 Bastien DHIVER
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# include <stdio.h>
# include <signal.h>

# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"

# define print_err(...)		fprintf(stderr, __VA_ARGS__)

typedef	struct user_regs_struct	t_regs;

typedef unsigned long long int	long_stuff;

extern pid_t			g_pid;

typedef	struct			s_args
{
  char				**av;
  char				**env;
}				t_args;

/*
**find_executable.c
*/
char				*find_executable(char *name);

/*
**trace.c
*/
int				be_the_child(t_args *arg);
int				be_the_parent(void);

/*
** utils.c
*/
int				display_error(int);

/*
** print_signals.c
*/
void				aff_signal(siginfo_t *);

/*
** signals.c
*/
void				get_sigint(int);
int				aff_end(int);

#endif /*FTRACE_H_*/
