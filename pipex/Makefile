# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:16:20 by ilyanar           #+#    #+#              #
#    Updated: 2024/01/10 12:20:04 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = pipex
BONUS_NAME= pipex_bonus

LIBFT_PATH = ./libft/
BONUS_PATH = ./bonus/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)

BONUS_FILES = $(BONUS_PATH)checker $(FILES)

CBONUS_FILES = $(BONUS_FILES:%=%.c)

FILES = pipex \

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

bonus: $(BONUS_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(CFILES) main.c $(LIBFT_LIB) -o $(NAME)
	@echo ""

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

$(BONUS_NAME): $(CBONUS_FILES) $(LIBFT_LIB)
	@printf "\t⏳Compiling bonus :3 $<...⌛️\r"
	@$(CC) $(CFLAGS) $(CBONUS_FILES) $(LIBFT_LIB) -o $(BONUS_NAME)
	@printf "\33[2K"
	@echo "\t$(BONUS_NAME) compiled ✅"

.PHONY : clean fclean all re
