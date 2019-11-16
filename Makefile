# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 17:16:42 by aait-ihi          #+#    #+#              #
#    Updated: 2019/11/15 19:40:59 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = fractol.c draw.c event.c julia.c mandelbrot.c multilbrot.c color.c burning_chip.c tricorn.c feigenbaum.c eyebrot.c newton.c

LIB_FT = libft/libft.a

MLX_PATH = /usr/local/

OBJ = $(SRC:%c=%o)

all : $(FDF)


$(LIB_FT) : lib

lib:
	make -C libft

$(FDF) :$(LIB_FT) $(OBJ)  fractol.h
	$(CC) -o $(FDF) $(CFLAGS) $(OBJ) $(LIB_FT) libmlx.a -framework OpenGL -framework AppKit

clean :
	#make clean -C libft
	/bin/rm -rf $(OBJ)

fclean : clean
	#make fclean -C libft
	/bin/rm -rf $(FDF)

re : fclean all
