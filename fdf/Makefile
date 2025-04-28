# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:41:52 by ilyanar           #+#    #+#              #
#    Updated: 2025/04/10 17:01:57 by ilyanar          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -framework OpenGL -framework AppKit

RM = rm -rf

NAME = fdf

LIBFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

LIBFT_LIB = $(LIBFT_PATH:%=%libft.a)
MLX = $(MLX_PATH:%=%libmlx.a)

FILES = fdf_main \
		fdf_color \
		fdf_maths \
		fdf_config \
		fdf_draw_hud \
		fdf_draw_numbers \
		fdf_draw_pixel \
		fdf_keys \
		fdf_min_max \
		fdf_parsing

CFILES = $(FILES:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) clean

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)

re :
	@make fclean
	@make all

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
