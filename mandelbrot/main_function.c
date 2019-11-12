/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:38:27 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/11 23:24:21 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static void init(t_fractol *fractol)
{
	fractol->x1 = -2.1;
	fractol->x2 = 0.6;
	fractol->y1 = -1.2;
	fractol->y2 = 1.2;
	fractol->zoom_x = (fractol->zoom.zoom * (WIN_WIDTH - MENU_WIDTH)) / 2.7;
	fractol->zoom_y = (fractol->zoom.zoom * WIN_HIEGHT) / 2.4;
	fractol->iteration = 50;
}

void iterate(t_complex c,t_point p, t_fractol *fractol)
{
    int i;
    long double tmp;
	t_complex z;

	z = (t_complex){0,0};
    i = 0;
    while (1)
    {
        tmp = z.r;
        z.r = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = 2 * z.i * tmp + c.i;
        i++;
        if (z.r * z.r + z.i * z.i < 4.0 && i < fractol->iteration)
            continue;
        break;
    }
    if (i == fractol->iteration)
        put_pixel(&fractol->img,p.x, p.y, 0);
	else
		put_pixel(&fractol->img,p.x, p.y, 0xff0100 * i * i);

}

void fractol1(t_fractol *fractol)
{
    int x;
    int y;
    t_complex c;

	init(fractol);

    y = fractol->zoom.y;
    while (y < WIN_HIEGHT + fractol->zoom.y)
    {
        x = fractol->zoom.x;
        while (x < WIN_WIDTH + fractol->zoom.x)
        {
            c.r = x / fractol->zoom_x + fractol->x1;
			c.i = y / fractol->zoom_y + fractol->y1;
            iterate(c, (t_point){x - fractol->zoom.x ,y - fractol->zoom.y}, fractol);
            x++;
        }
        y++;
    }
	draw_line(fractol, (t_point){660,0}, (t_point){660,700}, 0xffffff);
	draw_line(fractol, (t_point){629,0}, (t_point){629,700}, 0xffffff);
	draw_line(fractol, (t_point){664,0}, (t_point){664,700}, 0xffffff);
}
