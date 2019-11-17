/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:07:07 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/17 07:49:42 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_zoom_iteration(t_fractol *fractol)
{
	char		*zoom;
	char		*iter;
	const int	c = 0xffffff;

	zoom = ft_itoa(fractol->zoom.scale);
	iter = ft_itoa(fractol->iteration);
	draw_rectangle((t_point){10, 70}, (t_point){300, 120}, MENU_COLOR, fractol);
	PUT_STRING(fractol, START_X_MENU, 70, c, "zoom      :");
	PUT_STRING(fractol, 130, 70, c, zoom);
	PUT_STRING(fractol, START_X_MENU, 90, c, "iteration :");
	PUT_STRING(fractol, 130, 90, c, iter);
}

void	draw_title(t_fractol *fractol)
{
	draw_rectangle((t_point){0, 0}, (t_point){300, 62}, MENU_COLOR, fractol);
	PUT_STRING(fractol, (300 - ft_strlen(fractol->fractal_name) * 10) / 2, 10,
											0xffffff, fractol->fractal_name);
	PUT_STRING(fractol, (300 - ft_strlen(fractol->fractal_equation) * 10) / 2,
									30, 0xffffff, fractol->fractal_equation);
}

void	draw_colors_slide(t_fractol *fractol)
{
	t_point		p1;
	t_point		p2;
	int			i;
	const int	color[3] = {0xff, 0xff00, 0xff0000};
	int			y;

	i = 0;
	while (i < 3)
	{
		y = Y_COLOR_SLIDE + i * COLOR_SLIDE_HEIGHT + i * Y_STEP;
		p1 = (t_point){0, y};
		p2 = (t_point){300, p1.y + COLOR_SLIDE_HEIGHT};
		draw_rectangle(p1, p2, MENU_COLOR, fractol);
		p1 = (t_point){START_X_MENU, y + 5};
		p2 = (t_point){p1.x + 255, p1.y + 2};
		draw_rectangle(p1, p2, color[i], fractol);
		p1 = (t_point){START_X_MENU +
					(fractol->colors.c[fractol->colors.i] >> (i * 8) & 255), y};
		p2 = (t_point){p1.x + 5, p1.y + COLOR_SLIDE_HEIGHT};
		draw_rectangle(p1, p2, 0xffffff, fractol);
		i++;
	}
}

void	draw_colors_selector(t_fractol *fractol)
{
	t_point	p1;
	t_point	p2;
	int		i;

	i = fractol->colors.i;
	p1 = (t_point){0, Y_COLOR_SELECTOR};
	p2 = (t_point){300, Y_COLOR_SELECTOR + Y_STEP};
	draw_rectangle(p1, p2, MENU_COLOR, fractol);
	p1 = (t_point){START_X_MENU + i * 50 + i * Y_STEP + 20, Y_COLOR_SELECTOR};
	p2 = (t_point){p1.x + 10, p1.y + 5};
	draw_rectangle(p1, p2, fractol->colors.c[i], fractol);
	draw_colors_slide(fractol);
}

void	draw_colors(t_fractol *fractol)
{
	t_point	p1;
	t_point	p2;
	int		i;

	i = 0;
	while (i < 4)
	{
		p1 = (t_point){START_X_MENU + i * 50 + i * Y_STEP, Y_COLORS};
		p2 = (t_point){p1.x + COLORS_WIDTH, p1.y + COLORS_HEIGHT};
		draw_rectangle(p1, p2, fractol->colors.c[i], fractol);
		i++;
	}
	draw_colors_selector(fractol);
}
