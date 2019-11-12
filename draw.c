/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:37:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/11 22:24:17 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < WIN_WIDTH - MENU_WIDTH && y >= 0 && y < WIN_HIEGHT)
	{
		i = (x * img->bpp / 8) + (y * img->size_line);
		img->data[i] = color;
		img->data[++i] = color >> 8;
		img->data[++i] = color >> 16;
		//ft_printf("put pixel(%d,%d)\n", x , y);
	}
}

void		draw_line(t_fractol *fdf, t_point p1, t_point p2, int color)
{
	t_draw_line	v;

	v = (t_draw_line){0, p2.x - p1.x, p2.y - p1.y, 0, 0};
	v = (t_draw_line){0, v.dx, v.dy, SIGN(v.dx), SIGN(v.dy)};
	while (v.dx || v.dy)
	{
		put_pixel(&fdf->img, p1.x, p1.y, color);
		v.diff += ABS(v.dx) < ABS(v.dy) ? (double)ABS(v.dx) / (double)ABS(v.dy)
				: (double)ABS(v.dy) / (double)ABS(v.dx);
		p1.x += (ABS(v.dx) < ABS(v.dy) ? v.diff >= 1 : 1) * v.sign_dx;
		p1.y += (ABS(v.dx) > ABS(v.dy) ? v.diff >= 1 : 1) * v.sign_dy;
		v.dx += (ABS(v.dx) > ABS(v.dy) || v.diff >= 1) * v.sign_dx * -1;
		v.dy += (ABS(v.dx) < ABS(v.dy) || v.diff >= 1) * v.sign_dy * -1;
		v.diff -= v.diff >= 1;
	}
	put_pixel(&fdf->img, p1.x, p1.y, color);
}

void		clean_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HIEGHT)
	{
		j = 0;
		while (j < WIN_WIDTH - MENU_WIDTH)
			put_pixel(img, j++, i, 0x272721);
		i++;
	}
}

void render(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx_ptr,
							fractol->win_ptr,
							fractol->img.ptr,
							MENU_WIDTH, 0);
}
