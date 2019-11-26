/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:42:51 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 02:34:15 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_select(int x, int y, t_fractol *fractol)
{
	int	i;
	int	x_color;

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

void	color_slide(int x, int y, t_fractol *fractol)
{
	int			i;
	int			y_slide;
	t_rgb_color	color;
	int			*colors;

	color.c = fractol->colors.c[fractol->colors.i];
	colors = (int[3]){color.rgb.b, color.rgb.g, color.rgb.r};
	i = -1;
	if (BETWEEN(x, START_X_MENU, START_X_MENU + 255))
	{
		x -= START_X_MENU;
		while (++i < 3)
		{
			y_slide = Y_COLOR_SLIDE + i * COLOR_SLIDE_HEIGHT + i * Y_STEP;
			if (BETWEEN(y, y_slide, y_slide + COLOR_SLIDE_HEIGHT))
			{
				colors[i] = x;
				color.c = colors[2] << 16 | colors[1] << 8 | colors[0];
				fractol->colors.c[fractol->colors.i] = color.c;
				break ;
			}
		}
		draw_colors(fractol);
	}
	fractol->run(fractol);
}

void	fractal_move(int button, t_fractol *fractol)
{
	if (button == 123)
		fractol->zoom.x -= 10 / fractol->zoom.scale;
	else if (button == 124)
		fractol->zoom.x += 10 / fractol->zoom.scale;
	else if (button == 126)
		fractol->zoom.y -= 10 / fractol->zoom.scale;
	else
		fractol->zoom.y += 10 / fractol->zoom.scale;
	fractol->run(fractol);
}

void	zoom(int button, int x, int y, t_fractol *fractol)
{
	double	old_zoom;

	if (button == 4 && fractol->zoom.scale * 0.9090909090909091 <= 1.1)
		return ;
	x -= MENU_WIDTH;
	old_zoom = fractol->zoom.scale;
	fractol->zoom.scale *= button == 5 ? 1.1 : 0.9090909090909091;
	fractol->zoom.x += x / fractol->zoom.scale - x / old_zoom;
	fractol->zoom.y += y / fractol->zoom.scale - y / old_zoom;
	fractol->iteration += button == 5 ? 1 : -1;
	draw_zoom_iteration(fractol);
	fractol->run(fractol);
}
