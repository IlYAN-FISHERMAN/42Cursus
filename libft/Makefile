.PHONY : clean, fclean, all, re

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
NAME = libft.a
CFILE = %.c
OFILE = %.o

all : $(NAME)

$(NAME) : $(OFILE)
	ar -rc $(NAME) $(OFILE)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : clean fclean
