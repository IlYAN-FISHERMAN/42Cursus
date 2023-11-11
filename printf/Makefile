# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:53:51 by ilyanar           #+#    #+#              #
#    Updated: 2023/11/11 02:43:11 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libftprintf.a


CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)


FILES = ft_printf \
	ft_printf_utils

all : $(NAME)

COMPIL : $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES) -I.

$(NAME) : $(OFILES)
	ar -rc $@ $(OFILES)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
