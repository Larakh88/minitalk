# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 11:03:55 by lel-khou          #+#    #+#              #
#    Updated: 2022/03/18 11:57:51 by lel-khou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CFILES = server.c client.c
OBJS = $(CFILES:.c=.o)
LIBFT = libft.a
LIBS = -L./libft -lft

all: $(LIBFT) server client

$(LIBFT) : 
	@make -C libft

server : server.o
	$(CC) $(CFLAGS) server.o $(LIBS) -o server

client : client.o 
	$(CC) $(CFLAGS) client.o $(LIBS) -o client

clean:
	$(RM) $(OBJS)
	@make clean -C libft
	
fclean: clean
	@make fclean -C libft
	$(RM) server client

re: fclean all
