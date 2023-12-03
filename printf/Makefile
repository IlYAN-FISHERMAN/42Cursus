 **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:53:51 by ilyanar           #+#    #+#              #
#    Updated: 2023/11/26 00:48:01 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libftprintf.a

LIBFT_PATH = ./libft/

LIBFT_FILES = ft_strlen \
	      ft_strchr

LIBFT_OFILES = $(LIBFT_FILES:%=$(LIBFT_PATH)%.o)

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

FILES = ft_printf \
	ft_printf_utils

all : $(NAME)

$(NAME) : $(OFILES) $(LIBFT_PATH)Makefile
	make -C $(LIBFT_PATH) all
	ar -rc $@ $(OFILES) $(LIBFT_OFILES)

clean :
	$(RM) $(OFILES)
	make -C $(LIBFT_PATH) fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
