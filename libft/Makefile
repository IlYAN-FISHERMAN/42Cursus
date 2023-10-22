# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:53:51 by ilyanar           #+#    #+#              #
#    Updated: 2023/10/22 19:05:10 by ilyanar          ###   ########.fr        #
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
		 #ft_lstdelone \
	     ft_lstclear \
	     ft_lstiter \
	     ft_lstmap \#

FILES = ft_strlen \
	ft_memmove \
	ft_memcpy \
	ft_strlcpy \
	ft_strlcat \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_memset \
	ft_bzero \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_memcmp \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_lstnew \

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
