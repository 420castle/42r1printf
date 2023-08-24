# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 12:11:06 by adiaz-be          #+#    #+#              #
#    Updated: 2023/08/24 15:18:25 by marcofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

main: main.c
	$(CC) $(CFLAGS) -o main main.c

run: main
	./main | cat -A

clean:
	rm -f main