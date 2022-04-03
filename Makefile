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

NAME = server client $(LIBFT)

all: $(NAME)

$(LIBFT) : 
	@make -C libft

server: server.o libft
	$(CC) $(CFLAGS) -o $@ $< -L./libft -lft

client: client.o libft
	$(CC) $(CFLAGS) -o $@ $< -L./libft -lft

clean:
	rm -f $(OBJS)
	make -C libft clean
	
fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all
