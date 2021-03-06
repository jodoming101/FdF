# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/16 16:34:04 by jodoming     #+#   ##    ##    #+#        #
#    Updated: 2018/06/05 15:51:31 by jodoming    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   fdf
LIB_DIR     =   ./incl/
HEADER      =   fdf.h
FILENAMES   =   main.c parser.c ft_draw.c

SOURCES     =   $(addprefix ./, $(FILENAMES))
OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

L_FT        =   ./libft
LIB_LNK     =   -L $(L_FT) -l ft
LIB_INC     =   -I $(L_FT)/libft.h

LMLX		=	minilibx_macos
LMX_LNK		=	-L $(LMLX) -l mlx
LMX_INC		=	-I $(LMLX)/mlx.h

FLG			=	
FLG_MX		=	-framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

clean:
		rm -rf build/
		@$(MAKE) -C $(L_FT) clean

fclean: clean
		rm -f $(NAME)
		@$(MAKE) -C $(L_FT) fclean

re:
	    @$(MAKE) fclean
		@$(MAKE) all

build:
		mkdir build/

$(NAME): $(OBJECTS)
	    @$(MAKE) -C $(L_FT)
		gcc $(FLG) -I $(HEADER) $(OBJECTS) $(LIB_LNK) $(LMX_LNK) $(FLG_MX) -o $@

build/%.o: ./%.c | build
	    gcc $(FLG) $(LIB_INC) -I $(HEADER) -c $< -o $@
