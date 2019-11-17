/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:28:56 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/17 07:42:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*iterate(t_complex z, t_point p, t_fractol *fractol)
{
	int			i;
	long double	tmp;
	t_complex	c;

	c = (t_complex){1, 1};
	i = 0;
	while (1)
	{
		tmp = z.r;
		z.r = (pow(z.r, 3) + 3 * z.r * -(z.i * z.i)) - fractol->julia_const.r;
		z.i = (3 * tmp * tmp * z.i - pow(z.i, 3)) - fractol->julia_const.i;
		i++;
		if (z.r * z.r + z.i * z.i < 4.0 && i < fractol->iteration)
			continue;
		break ;
	}
	put_pixel(&fractol->img, p.x, p.y,
								fractol->color(i, fractol->iteration, fractol));
	return (NULL);
}

static void	*fractol1(void *arg)
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
		pthread_create(&thread_id[i], NULL, fractol1, &thread_arg[i]);
		x += fractol->x_thread;
		i++;
	}
	while (i-- > 0)
		pthread_join(thread_id[i], NULL);
	draw_zoom_iteration(fractol);
	render(fractol);
}

static int	move(int x, int y, t_fractol *fractol)
{
	if (!fractol->pause)
	{
		x -= MENU_WIDTH;
		fractol->julia_const.r = (double)(x - 350) / 90.;
		fractol->julia_const.i = (double)(y - 350) / 90.;
		run(fractol);
	}
	return (0);
}

void		init_newton(t_fractol *fractol)
{
	fractol->zoom = (t_zoom){250, 1.4, 1.4};
	fractol->iteration = 150;
	fractol->julia_const = (t_complex){0.433333, 0.};
	fractol->init = init_newton;
	fractol->run = run;
	fractol->colors.c[0] = WHITE;
	fractol->colors.c[1] = 0xff7f00;
	fractol->colors.c[2] = 0xf58f2a;
	fractol->colors.c[3] = 0xffb66d;
	fractol->fractal_name = "Julia ^ 3";
	fractol->fractal_equation = "z^3 + c";
	draw_title(fractol);
	mlx_hook(fractol->win_ptr, 6, 1, move, fractol);
	run(fractol);
}
