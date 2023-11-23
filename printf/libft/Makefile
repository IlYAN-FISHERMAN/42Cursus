# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:53:51 by ilyanar           #+#    #+#              #
#    Updated: 2023/11/22 22:24:42 by ilyanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libft.a


CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

ALLCFILES = $(ALLFILES:%=%.c)

ALLOFILES = $(ALLFILES:%=%.o)

ALLFILES = $(FILES) $(BONUSFILES)

BONUSFILES = ft_lstnew \
	     ft_lstadd_front \
	     ft_lstsize \
	     ft_lstlast \
	     ft_lstadd_back \
			 ft_lstdelone \
			 ft_lstclear \
	     ft_lstiter \
	     ft_lstmap \

FILES = ft_strlen \
	ft_strchr \
	ft_putchar_fd \
	ft_putnbr_fd \
	ft_putnbr_base \

all : $(NAME)

COMPIL : $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES) -I.

$(NAME) : $(OFILES)
	ar -rc $@ $(OFILES)

bonus : $(ALLOFILES)
	ar -rcs $(NAME) $(ALLOFILES)

clean :
	$(RM) $(OFILES)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all re
