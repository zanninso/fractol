/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_chip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:38:27 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/17 07:31:13 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*iterate(t_complex c, t_point p, t_fractol *fractol)
{
	int			i;
	long double	tmp;
	t_complex	z;

	z = (t_complex){0, 0};
	i = 0;
	while (1)
	{
		tmp = fabsl(z.r);
		z.r = fabsl(z.r * z.r - z.i * z.i + c.r);
		z.i = fabsl(2 * z.i * tmp + c.i);
		i++;
		if (z.r * z.r + z.i * z.i < 4 && i < fractol->iteration)
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

void		init_burning_ship(t_fractol *fractol)
{
	fractol->zoom = (t_zoom){175, 2, 2};
	fractol->iteration = 50;
	fractol->run = run;
	fractol->init = init_burning_ship;
	fractol->colors.c[0] = BLUE;
	fractol->colors.c[1] = 0xe8daa9;
	fractol->colors.c[2] = 0xd5b16d;
	fractol->colors.c[3] = 0x8d5c38;
	fractol->fractal_name = "Burning Ship";
	fractol->fractal_equation = "|z^2| + c";
	draw_title(fractol);
	mlx_hook(fractol->win_ptr, 6, 1, NULL, NULL);
	run(fractol);
}
