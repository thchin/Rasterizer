# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thchin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:48:39 by thchin            #+#    #+#              #
#    Updated: 2017/02/24 00:43:32 by thchin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/clear.c\
	  srcs/draw.c\
	  srcs/edge.c\
	  srcs/edge_table.c\
	  srcs/event.c\
	  srcs/glfrustum.c\
	  srcs/get.c\
	  srcs/glulookat.c\
	  srcs/gluperspective.c\
	  srcs/grid.c\
	  srcs/init.c\
	  srcs/img.c\
	  srcs/main.c\
	  srcs/matrix.c\
	  srcs/print.c\
	  srcs/rgb.c\
	  srcs/scanline.c\
	  srcs/transformation.c\
	  srcs/vector.c\
	  srcs/viewport.c\
	  srcs/z_buffer.c\

OBJ = $(SRC:.c=.o)

LIB = make -C ./libft

LIBDIR = -lft -L./libft

CFLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework Appkit

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB)
	gcc -o $(NAME) $(CFLAGS) $(MLX) $(LIBDIR) $(OBJ)

clean:
	$(LIB) clean
	rm -rf $(OBJ)

fclean: clean
	$(LIB) fclean
	rm -rf $(NAME)

re: fclean all
