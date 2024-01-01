# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 00:47:42 by ilyanar           #+#    #+#              #
#    Updated: 2023/12/28 23:00:20 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = push_swap

LIBFT_PATH = ./libft/

LIBFT_FILES = ft_lstadd_back \
			  ft_lstadd_front \
			  ft_lstclear \
			  ft_lstlast \
			  ft_lstnew \
			  ft_lstsize \
			  ft_printf \
			  ft_atoi \
			  ft_bzero \
			  ft_printf_utils \
			  ft_split \
			  ft_strlen \
			  ft_calloc \
			  ft_memcpy


LIBFT_CFILES = $(LIBFT_FILES:%=$(LIBFT_PATH)%.c)

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

OFILES = $(FILES:%=%.o)

all : $(NAME)

$(NAME) : $(CFILES) $(LIBFT_CFILES)
	 $(CC) $(CFLAGS) $(CFILES) $(LIBFT_CFILES) -o push_swap

clean :
	$(RM) $(OFILES)
	make -C $(LIBFT_PATH) fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
