# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:41:52 by ilyanar           #+#    #+#              #
#    Updated: 2024/03/07 13:53:33 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast

MLXFLAGS = -framework OpenGL -framework AppKit

RM = rm -rf

NAME = fdf

LIBFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)
MLX = $(MLX_PATH:%=%libmlx.a)

FILES = fdf \
		fdf_utils1 \
		fdf_maths

CFILES = $(FILES:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) clean

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)

re : fclean all

debug : $(CFILES) $(LIBFT_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_LIB) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

$(MLX): $(MLX_PATH)Makefile
	@make -C $(MLX_PATH) all

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

.PHONY : clean fclean all debug re
