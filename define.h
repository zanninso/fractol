/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:03:23 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 02:31:37 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H

# define WIN_WIDTH 1000
# define WIN_HIEGHT 700
# define MENU_WIDTH 300
# define MAX_THREAD 4
# define DEFINE_H
# define USAGE "FRACTOL\n\nchoice:\n0 : Mandelbrot\n1 : Julia\n2 : New multibro"
# define USAGE2 "t\n3 : Burning ship\n4 : Tricorn\n5 : Feigenbaum\n6 : batman\n"
# define WHITE 0xffffff
# define RED 0xff0000
# define YELLOW 0xffff00
# define PURPLE 0xc832aa
# define GREEN 0xff00
# define BLUE 0xff
# define MENU_COLOR 0x525252
# define START_Y_MENU 120
# define START_X_MENU 20
# define Y_STEP 20
# define Y_COLOR_TITLE START_Y_MENU
# define Y_COLOR_SELECTOR Y_COLOR_TITLE + Y_STEP + STRING_HEIGHT
# define Y_COLORS Y_COLOR_SELECTOR + Y_STEP
# define COLORS_WIDTH 50
# define COLORS_HEIGHT 20
# define Y_COLOR_SLIDE Y_COLOR_SELECTOR + Y_STEP + COLORS_WIDTH
# define COLOR_SLIDE_HEIGHT 10
# define STRING_HEIGHT 10
# define T1 "Change color"
# define Y_FRACTAL_CHANGE Y_COLOR_SLIDE + (Y_STEP + COLOR_SLIDE_HEIGHT) * 3
# define T2 "Fractal switch    : </>"
# define Y_ITERATION Y_FRACTAL_CHANGE + Y_STEP + STRING_HEIGHT
# define T3 "Iteration up/down : +/-"
# define Y_CHANGE_COLOR Y_ITERATION + Y_STEP + STRING_HEIGHT
# define T4 "Change color mode : c"
# define Y_RESET Y_CHANGE_COLOR + Y_STEP + STRING_HEIGHT
# define T5 "Reset             : r"
# define Y_MOVE Y_RESET + Y_STEP + STRING_HEIGHT
# define T6 "Move              : arrow"
# define PUT_STRING(f, x, y, c, s) mlx_string_put(f->mlx_ptr,f->win_ptr,x,y,c,s)
#endif
