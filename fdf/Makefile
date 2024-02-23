# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:41:52 by ilyanar           #+#    #+#              #
#    Updated: 2024/02/21 20:03:18 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast

RM = rm -rf

NAME = fdf

LIBFT_PATH = ./libft/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)

FILES = fdf

CFILES = $(FILES:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "
	@$(MAKE) -C $(LIBFT_PATH) fclean

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re : fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_LIB) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

.PHONY : clean fclean all re
