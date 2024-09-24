# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:53:51 by ilyanar           #+#    #+#              #
#    Updated: 2024/09/24 14:41:22 by ilyanar          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = libft.a

STR_U = src/str/utils/
STR_A = src/str/allocation/
MEMO = src/memory/
CONV = src/convert/
FT_IS = src/ft_is/
GNL = src/gnl/
PRINTF = src/printf/
LST = src/lst/

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

ALLCFILES = $(ALLFILES:%=%.c)

ALLOFILES = $(ALLFILES:%=%.o)

FILES = $(STR_U)ft_strlen \
	$(STR_U)ft_strlcpy \
	$(STR_U)ft_strlcat \
	$(STR_U)ft_strchr \
	$(STR_U)ft_strrchr \
	$(STR_U)ft_strncmp \
	$(STR_U)ft_strnstr \
	$(STR_U)ft_putchar_fd \
	$(STR_U)ft_putstr_fd \
	$(STR_U)ft_putendl_fd \
	$(STR_U)ft_rev_tab \
	$(STR_U)ft_count_char \
	$(STR_U)ft_strcmp \
	$(STR_U)ft_striteri \
	$(STR_U)ft_free_tab

FILES += $(STR_A)ft_bzero \
	$(STR_A)ft_calloc \
	$(STR_A)ft_joint_all \
	$(STR_A)ft_strr_realloc \
	$(STR_A)ft_split \
	$(STR_A)ft_strdup \
	$(STR_A)ft_strjoin \
	$(STR_A)ft_strtrim \
	$(STR_A)ft_strmapi \
	$(STR_A)ft_substr

FILES += $(MEMO)ft_memcpy \
	$(MEMO)ft_memmove \
	$(MEMO)ft_memset \
	$(MEMO)ft_memchr \
	$(MEMO)ft_memcmp

FILES += $(CONV)ft_putnbr_fd \
	$(CONV)ft_atoi \
	$(CONV)ft_itoa \
	$(CONV)ft_putnbr_base \
	$(CONV)ft_atoi_base

FILES += $(FT_IS)ft_isalpha \
	$(FT_IS)ft_isdigit \
	$(FT_IS)ft_isalnum \
	$(FT_IS)ft_isascii \
	$(FT_IS)ft_isprint \
	$(FT_IS)ft_toupper \
	$(FT_IS)ft_tolower

FILES += $(GNL)get_next_line \
	$(GNL)get_next_line_utils

FILES += $(PRINTF)ft_printf \
	$(PRINTF)ft_printf_utils

FILES += $(LST)ft_lstnew \
    $(LST)ft_lstadd_front \
	$(LST)ft_lstsize \
	$(LST)ft_lstlast \
	$(LST)ft_lstadd_back \
	$(LST)ft_lstdelone \
	$(LST)ft_lstclear \
	$(LST)ft_lstiter \
	$(LST)ft_lstmap

all : $(NAME)

%.o : %.c
	@printf "\t⏳Compiling :3 $<...⌛️\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME) : $(OFILES)
	@printf "\tcompiling...\r"
	@ar -rc $@ $(OFILES)
	@printf "\33[2K"
	@echo "\t$(NAME) compiled ✅"

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ "
	@$(RM) $(OFILES)

fclean : clean
	@echo "\n [$(NAME)] - supressions du reste... 🗑️"
	@echo ""
	@$(RM) $(NAME)

re :
	@make fclean
	@make all

.PHONY : clean fclean all re
