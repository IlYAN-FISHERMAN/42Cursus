# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 21:23:03 by ilyanar           #+#    #+#              #
#    Updated: 2024/01/05 00:59:28 by ilyanar          ###   ########.fr        #
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
	$(MAKE) -C $(LIBFT_PATH) fclean

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

bonus: $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(CFILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CFILES) main.c $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	make -C $(LIBFT_PATH) all

$(BONUS_NAME): $(CBONUS_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(CBONUS_FILES) $(LIBFT_LIB) -o $(BONUS_NAME)

.PHONY : clean fclean all re
