/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:37:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/16 06:45:37 by aait-ihi         ###   ########.fr       */
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
		//ft_printf("put pixel(%d,%d)\n", x , y);
	}
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
			put_pixel(img, j++, i,(t_argb){0x21, 0x27, 0x27});
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

void	draw_rectangle(t_point p1, t_point p2,int color, t_fractol *fractol)
{
	int i;

	while(p1.y < p2.y)
	{
		i = p1.x;
		while(i < p2.x)
		{
			mlx_pixel_put(&fractol->mlx_ptr,fractol->win_ptr, i, p1.y, color);
			i++;
		}	
		p1.y++;
	}
}

void draw_colors_slide(t_fractol *fractol)
{
	t_point p1;
	t_point p2;
	int i;
	const int color[3] = {0xff,0xff00, 0xff0000};
	int y;

	i = 0;
	while(i < 3)
	{
		y = Y_COLOR_SLIDE + i * COLOR_SLIDE_HEIGHT + i * Y_STEP;
		p1 = (t_point){0, y};
		p2 =  (t_point){300 , p1.y + COLOR_SLIDE_HEIGHT};
		draw_rectangle(p1, p2, MENU_COLOR, fractol);
		p1 = (t_point){START_X_MENU, y + 5};
		p2 =  (t_point){p1.x + 255 , p1.y + 2};
		draw_rectangle(p1, p2,color[i],fractol);
		p1 = (t_point){START_X_MENU + (fractol->colors.c[fractol->colors.i] >> (i * 8) & 255), y};
		p2 = (t_point){p1.x + 5 , p1.y + COLOR_SLIDE_HEIGHT};
		draw_rectangle(p1, p2,0xffffff,fractol);
		i++;
	}
}

void draw_colors_selector(t_fractol *fractol)
{
	t_point p1;
	t_point p2;
	int i;

	i = fractol->colors.i;
	p1 = (t_point){0, Y_COLOR_SELECTOR};
	p2 = (t_point){300, Y_COLOR_SELECTOR + Y_STEP};
	draw_rectangle(p1, p2, MENU_COLOR, fractol);
	p1 = (t_point){START_X_MENU + i * 50 + i * Y_STEP + 20, Y_COLOR_SELECTOR};
	p2 =  (t_point){p1.x + Y_STEP , p1.y + 5};
	draw_rectangle(p1, p2,fractol->colors.c[i],fractol);
	draw_colors_slide(fractol);

}

void draw_colors(t_fractol *fractol)
{
	t_point p1;
	t_point p2;
	int i;

	i = 0;
	while(i < 4)
	{
		p1 = (t_point){START_X_MENU + i * 50 + i * Y_STEP, Y_COLORS};
		p2 =  (t_point){p1.x + COLORS_WIDTH , p1.y + COLORS_HEIGHT};
		draw_rectangle(p1, p2,fractol->colors.c[i],fractol);
		i++;
	}
	draw_colors_selector(fractol);
}

void draw_menu(t_fractol *fractol)
{
	t_point p1;
	t_point p2;
	int i;

	i = 0;
	p1 = (t_point){0,0};
	p2 = (t_point){300,700};
	draw_rectangle(p1, p2, MENU_COLOR, fractol);
	draw_colors(fractol);
}