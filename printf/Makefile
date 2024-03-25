# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 10:01:33 by ilyanar           #+#    #+#              #
#    Updated: 2024/03/24 19:28:06 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = ft_printf

LIBFT_PATH = ./libft/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)

CFILES = $(FILES:%=%.c)

CBFILES = $(BFILES:%=%.c)

FILES = ft_printf \
		ft_printf_utils

BFILES = ft_printf_bonus \
		 ft_printf_utils_bonus

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME) : $(CFILES) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_LIB) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

bonus : $(CBFILES) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(CBFILES) $(LIBFT_LIB) -o $(NAME)
	@echo " \t$(NAME) compiled with bonus ✅"

clean :
	@$(RM) $(OFILES)
	@make -C $(LIBFT_PATH) fclean

fclean : clean
	@$(RM) $(NAME)

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

re : fclean all

.PHONY : clean fclean all re bonus
