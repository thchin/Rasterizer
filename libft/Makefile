# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thchin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:53:46 by thchin            #+#    #+#              #
#    Updated: 2017/02/23 04:04:42 by thchin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_abs.c\
	  ft_atoi.c\
	  ft_atoi_base.c\
	  ft_bzero.c\
	  ft_check_char.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_iterative_power.c\
	  ft_itoa.c\
	  ft_lstpushfront.c\
	  ft_lstpushback.c\
	  ft_lstdel.c\
	  ft_lstdelone.c\
	  ft_lstfind.c\
	  ft_lstforeach.c\
	  ft_lstfree.c\
	  ft_lstfreeone.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_lstmerge.c\
	  ft_lstnew.c\
	  ft_lstremoveone.c\
	  ft_lstswitch.c\
	  ft_nblen_base.c\
	  ft_nodenew.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclen.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strndup.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_degreetoradian.c\
	  ft_radiantodegree.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  get_next_line.c\

OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
