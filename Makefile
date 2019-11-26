# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 17:16:42 by aait-ihi          #+#    #+#              #
#    Updated: 2019/11/26 01:40:24 by aait-ihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC =	fractol.c draw.c event.c color.c menu.c event2.c julia.c\
		mandelbrot.c multilbrot.c burning_chip.c tricorn.c\
		feigenbaum.c batman.c julia3.c

LIB_FT = libft/libft.a

MLX_PATH = /usr/local/

OBJ = $(SRC:%c=%o)

all : $(NAME)


$(LIB_FT) : lib

lib:
	make -C libft

$(NAME) :$(LIB_FT) $(OBJ)  fractol.h
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FT) -lmlx  -L  $(MLX_PATH)lib/ -I $(MLX_PATH)include -framework OpenGL -framework AppKit

%.o : fractals/%.c fractol.h define.h
	$(CC) $(CFLAGS) -I . -o $@ -c $<

%.o : %.c fractol.h define.h
	$(CC) $(CFLAGS) -I . -o $@ -c $<

clean :
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re : fclean all
