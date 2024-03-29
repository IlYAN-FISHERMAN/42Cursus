# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 21:23:03 by ilyanar           #+#    #+#              #
#    Updated: 2024/01/12 17:25:01 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = push_swap
BONUS_NAME= checker

LIBFT_PATH = ./libft/
BONUS_PATH = ./bonus/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)

BONUS_FILES = $(BONUS_PATH)checker $(FILES)

CBONUS_FILES = $(BONUS_FILES:%=%.c)

FILES = count \
        ft_algo \
        ft_algo2 \
        ft_algo_repuch_to_a \
        move_set1 \
        move_set2 \
        push_swap \
        push_swap_utils \
        push_swap_utils_2

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
	@echo "\t$(NAME) created ✅"
	@echo "\n\nBest push_swap with more than 12 numbers, and less than 2000\nThis one is the opposite : (https://github.com/rpdjf/42-pushswap)"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

$(BONUS_NAME): $(CBONUS_FILES) $(LIBFT_LIB)
	@printf "\t⏳Compiling bonus :3 $<...⌛️\r"
	@$(CC) $(CFLAGS) $(CBONUS_FILES) $(LIBFT_LIB) -o $(BONUS_NAME)
	@printf "\33[2K"
	@echo "\t$(BONUS_NAME) compiled ✅"

.PHONY : clean fclean all re
