# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 00:47:42 by ilyanar           #+#    #+#              #
#    Updated: 2023/12/28 22:14:44 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = push_swap

LIBFT_PATH = ./libft/

LIBFT_FILES = ft_strlen \
			  ft_lstadd_back

LIBFT_OFILES = $(LIBFT_FILES:%=$(LIBFT_PATH)%.o)

FILES = count \
		ft_algo \
		ft_algo2 \
		ft_algo_repuch_to_a \
		move_set1 \
		moves_set2 \
		push_swap \
		push_swap_utils \
		push_swap_utils_2

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

all : $(NAME)

$(NAME) : $(OFILES) $(LIBFT_PATH)Makefile
	make -C $(LIBFT_PATH) all
	$(CC) $(CFLAGS) $(CFILES) -o push_swap

clean :
	$(RM) $(OFILES)
	make -C $(LIBFT_PATH) fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
