/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:15:23 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 01:04:34 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*iterate(t_complex z, t_point p, t_fractol *fractol)
{
	int			i;
	long double	tmp;

	i = 0;
	while (1)
	{
		tmp = z.r;
		z.r = (z.r * z.r) - (z.i * z.i) + fractol->julia_const.r;
		z.i = 2 * z.i * tmp + fractol->julia_const.i;
		i++;
		if (z.r * z.r + z.i * z.i < 4.0 && i < fractol->iteration)
			continue;
		break ;
	}
	put_pixel(&fractol->img, p.x, p.y,
								fractol->color(i, fractol->iteration, fractol));
	return (NULL);
}

static void	*calculate(void *arg)
{
	int			x;
	int			y;
	t_complex	c;
	t_fractol	*fractol;

	y = 0;
	fractol = ((t_thread_arg *)arg)->fractol;
	while (y < WIN_HIEGHT)
	{
		x = ((t_thread_arg *)arg)->x;
		while (x < ((t_thread_arg *)arg)->x_max)
		{
			c.r = x / fractol->zoom.scale - fractol->zoom.x;
			c.i = y / fractol->zoom.scale - fractol->zoom.y;
			iterate(c, (t_point){x, y}, fractol);
			x++;
		}
		y++;
	}
	return (NULL);
}

static void	run(t_fractol *fractol)
{
	int				x;
	int				i;
	pthread_t		thread_id[MAX_THREAD];
	t_thread_arg	thread_arg[MAX_THREAD];

	i = 0;
	x = 0;
	while (i < MAX_THREAD)
	{
		thread_arg[i] = (t_thread_arg){fractol, x, x + fractol->x_thread};
		pthread_create(&thread_id[i], NULL, calculate, &thread_arg[i]);
		x += fractol->x_thread;
		i++;
	}
	while (i-- > 0)
		pthread_join(thread_id[i], NULL);
	draw_zoom_iteration(fractol);
	render(fractol);
}

void		init_julia(t_fractol *fractol)
{
	fractol->zoom = (t_zoom){250, 1.4, 1.4};
	fractol->iteration = 300;
	fractol->julia_const = (t_complex){-0.53333, -0.52222222};
	fractol->run = run;
	fractol->init = init_julia;
	fractol->colors.c[0] = WHITE;
	fractol->colors.c[1] = 0x1f1f1f;
	fractol->colors.c[2] = 0x5f5f5f;
	fractol->colors.c[3] = 0x9f9f9f;
	fractol->fractal_name = "Julia";
	fractol->fractal_equation = "z^2 + c";
	draw_title(fractol);
	run(fractol);
}
