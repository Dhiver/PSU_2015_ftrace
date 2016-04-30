##
## Makefile for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
##
## Made by florian videau
## Login   <videau_f@epitech.net>
##
## Last update Sat Apr 30 18:59:37 2016 florian videau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic -std=c99
CFLAGS	+= -I$(INCF)

LDFLAGS	+= -lelf -ldl

NAME	= ftrace

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)ftrace.c		\
	  $(SRCF)find_executable.c	\
	  $(SRCF)print_signals.c	\
	  $(SRCF)print_syscalls.c	\
	  $(SRCF)signals.c		\
	  $(SRCF)trace.c		\
	  $(SRCF)utils.c		\
	  $(SRCF)load_elf.c		\
	  $(SRCF)get_name_from_addr.c	\
	  $(SRCF)J0rmb97.c		\
	  $(SRCF)S0rmb57.c		\
	  $(SRCF)l0rmb17.c		\
	  $(SRCF)D0rmbD7.c		\
	  $(SRCF)sib_base.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
