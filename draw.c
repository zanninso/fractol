/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:37:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/14 21:09:42 by aait-ihi         ###   ########.fr       */
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
		img->data[++i] = color.g >> 8;
		img->data[++i] = color.r >> 16;
		//ft_printf("put pixel(%d,%d)\n", x , y);
	}
}

// void		draw_line(t_fractol *fdf, t_point p1, t_point p2, int color)
// {
// 	t_draw_line	v;

// 	v = (t_draw_line){0, p2.x - p1.x, p2.y - p1.y, 0, 0};
// 	v = (t_draw_line){0, v.dx, v.dy, SIGN(v.dx), SIGN(v.dy)};
// 	while (v.dx || v.dy)
// 	{
// 		put_pixel(&fdf->img, p1.x, p1.y, color);
// 		v.diff += ABS(v.dx) < ABS(v.dy) ? (double)ABS(v.dx) / (double)ABS(v.dy)
// 				: (double)ABS(v.dy) / (double)ABS(v.dx);
// 		p1.x += (ABS(v.dx) < ABS(v.dy) ? v.diff >= 1 : 1) * v.sign_dx;
// 		p1.y += (ABS(v.dx) > ABS(v.dy) ? v.diff >= 1 : 1) * v.sign_dy;
// 		v.dx += (ABS(v.dx) > ABS(v.dy) || v.diff >= 1) * v.sign_dx * -1;
// 		v.dy += (ABS(v.dx) < ABS(v.dy) || v.diff >= 1) * v.sign_dy * -1;
// 		v.diff -= v.diff >= 1;
// 	}
// 	put_pixel(&fdf->img, p1.x, p1.y, color);
// }

void		clean_img(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HIEGHT)
	{
		j = 0;
		while (j < WIN_WIDTH - MENU_WIDTH)
			put_pixel(img, j++, i,(t_argb){0, 0x27, 0x27, 0x21});
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

void zoom(int button, int x, int y, t_fractol *fractol)
{
	double old_zoom;
	button = button == 1 ? 5 : button;
	x -= MENU_WIDTH;
	old_zoom = fractol->zoom.scale;
	fractol->zoom.scale *= button == 5 ? 1.1 : 0.7;
	fractol->zoom.x += x / fractol->zoom.scale - x / old_zoom;
	fractol->zoom.y += y / fractol->zoom.scale - y / old_zoom;
	fractol->iteration += button == 5 ? 1 : -1;
	fractol->run(fractol);
}
