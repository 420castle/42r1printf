# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcofer <marcofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 12:11:06 by adiaz-be          #+#    #+#              #
#    Updated: 2023/08/29 19:11:58 by marcofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC := $(filter-out main.c, $(wildcard *.c))

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs
MAIN = main.c
CC_MAIN = $(CC) $(CFLAGS) $(MAIN) -o main -L. -lft

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

run: $(NAME) clean
	$(CC) $(CFLAGS) main.c -o main -L. -lft
	./main | cat -A	

.PHONY:	all clean fclean re bonus
