/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:37:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 02:24:29 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, t_argb color)
{
	int	i;

	if (x >= 0 && x < WIN_WIDTH - MENU_WIDTH && y >= 0 && y < WIN_HIEGHT)
	{
		i = (x * img->bpp / 8) + (y * img->size_line);
		img->data[i] = color.b;
		img->data[++i] = color.g;
		img->data[++i] = color.r;
	}
}

void	render(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx_ptr,
							fractol->win_ptr,
							fractol->img.ptr,
							MENU_WIDTH, 0);
}

void	draw_rectangle(t_point p1, t_point p2, int color, t_fractol *fractol)
{
	int	i;

	while (p1.y < p2.y)
	{
		i = p1.x;
		while (i < p2.x)
		{
			mlx_pixel_put(&fractol->mlx_ptr, fractol->win_ptr, i, p1.y, color);
			i++;
		}
		p1.y++;
	}
}

void	draw_menu(t_fractol *fractol)
{
	t_point	p1;
	t_point	p2;
	int		i;

	i = 0;
	p1 = (t_point){0, 0};
	p2 = (t_point){300, 700};
	draw_rectangle(p1, p2, MENU_COLOR, fractol);
	PUT_STRING(fractol, START_X_MENU, Y_COLOR_TITLE, WHITE, T1);
	PUT_STRING(fractol, START_X_MENU, Y_FRACTAL_CHANGE, WHITE, T2);
	PUT_STRING(fractol, START_X_MENU, Y_ITERATION, WHITE, T3);
	PUT_STRING(fractol, START_X_MENU, Y_CHANGE_COLOR, WHITE, T4);
	PUT_STRING(fractol, START_X_MENU, Y_RESET, WHITE, T5);
	PUT_STRING(fractol, START_X_MENU, Y_MOVE, WHITE, T6);
}
