/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:43:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/16 06:58:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void color_select(int x, int y, t_fractol *fractol)
{
	int i;
	int x_color;

	i = 1;
	if (BETWEEN(y, Y_COLORS, Y_COLORS + COLORS_HEIGHT))
	{
		if (BETWEEN(x, START_X_MENU, START_X_MENU + COLORS_WIDTH))
			fractol->colors.i = 0;
		while (i < 4)
		{
			x_color = i * COLORS_WIDTH + i * Y_STEP + START_X_MENU;
			if (BETWEEN(x, x_color, x_color + COLORS_WIDTH))
				fractol->colors.i = i;
			i++;
		}
		draw_colors_selector(fractol);
	}
}

void color_slide(int x, int y, t_fractol *fractol)
{
	int i;
	int y_slide;
	int color[3];

	color[0] = fractol->colors.c[fractol->colors.i] & 255;
	color[1] = fractol->colors.c[fractol->colors.i] >> 8 & 255;
	color[2] = fractol->colors.c[fractol->colors.i] >> 16 & 255;
	i = 0;
	if (BETWEEN(x, START_X_MENU, START_X_MENU + 255))
	{
		x -= START_X_MENU;
		while (i < 3)
		{
			y_slide = Y_COLOR_SLIDE + i * COLOR_SLIDE_HEIGHT + i * Y_STEP;
			if (BETWEEN(y, y_slide, y_slide + COLOR_SLIDE_HEIGHT))
			{
				color[i] = x;
				fractol->colors.c[fractol->colors.i] = color[2] << 16| color[1] << 8 | color[0];
				break;
			}
			i++;
		}
		draw_colors(fractol);
	}
	fractol->run(fractol);
}

int mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5 || button == 4)
		zoom(button, x, y, fractol);
	if (button == 1)
	{
		color_select(x, y, fractol);
		color_slide(x, y, fractol);
	}
	return (0);
}

int key_press(int button, t_fractol *fractol)
{
	if (button == 49)
		fractol->pause ^= 1;
	else if (button == 1)
	{
		fractol->fractal = (fractol->fractal + 1) % 8;
		init_fractal(fractol);
	}
	else if (button == 8)
		change_color_mod(fractol);
	else if (button == 15)
		fractol->init(fractol);
	return (0);
}

void attach_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 2, 1, key_press, fractol);
}
