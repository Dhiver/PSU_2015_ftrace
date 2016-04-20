##
## Makefile for ftrace in /home/videau_f/rendu/PSU/PSU_2015_ftrace
##
## Made by florian videau
## Login   <videau_f@epitech.net>
##
## Started on  Wed Apr 13 11:06:17 2016 florian videau
## Last update Wed Apr 20 11:30:48 2016 Bastien DHIVER
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic
CFLAGS	+= -I$(INCF)

NAME	= ftrace

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)ftrace.c		\
	  $(SRCF)find_executable.c	\
	  $(SRCF)trace.c		\
	  $(SRCF)utils.c		\
	  $(SRCF)print_signals.c	\
	  $(SRCF)signals.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re