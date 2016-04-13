/*
** ftrace.h for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Tue Apr 12 14:07:13 2016 florian videau
** Last update Wed Apr 13 11:13:34 2016 florian videau
*/

#ifndef FTRACE_H_
# define FTRACE_H_

# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"

typedef	struct user_regs_struct	t_regs;

typedef	struct			s_args
{
  char				**av;
  char				**env;
}				t_args;

/*
**find_executable.c
*/
char	*find_executable(char *name);

/*
**trace.c
*/
int	be_the_child(t_args *arg);
int	be_the_parent(int pid);

/*
** utils.c
*/
int				display_error(int, int);

#endif /*FTRACE_H_*/
