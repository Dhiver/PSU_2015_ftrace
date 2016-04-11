## ## Makefile for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Thu Mar 31 13:20:36 2016 Bastien DHIVER
## Last update Mon Apr 11 11:31:08 2016 florian videau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic -std=c99
CFLAGS	+= -I$(INCF)

NAME	= ftrace

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)ftrace.c

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
