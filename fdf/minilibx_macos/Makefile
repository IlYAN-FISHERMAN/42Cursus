#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "\n [$(NOM)] - minilibx compiled... ♻️ "
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@echo "\n [$(NOM)] - Nettoyage fichier residuels... ♻️ "
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
