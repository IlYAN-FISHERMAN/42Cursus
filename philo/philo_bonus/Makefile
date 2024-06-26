# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:41:52 by ilyanar           #+#    #+#              #
#    Updated: 2024/06/08 20:20:07 by ilyanar          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -lpthread -Wall -Werror -Wextra

RM = rm -rf

NAME = philo

FILES = philo \
		philo_utils \
		init \
		checker \
		parsing \
		time

CFILES = $(FILES:%=%.c)

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️"
	@rm -f $(NAME)
	@echo ""

re :
	@make fclean
	@make all

debug_t : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=thread -o $(NAME)
	@echo " \t$(NAME) compiled with thread debug ✅"

debug_f : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address -o $(NAME)
	@echo " \t$(NAME) compiled with address debug ✅"

debug_v : $(CFILES)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -o $(NAME)
	@echo " \t$(NAME) compiled with address debug ✅"

.PHONY : clean fclean all debug re
