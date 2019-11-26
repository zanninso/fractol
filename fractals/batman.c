/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 02:24:40 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 01:04:47 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*iterate(t_complex c, t_point p, t_fractol *fractol)
{
	int			i;
	long double	tmp;
	long double	tmp2;
	t_complex	z;

	z = (t_complex){0, 0};
	i = 0;
	while (1)
	{
		tmp = z.r;
		if ((tmp2 = c.i * c.i + c.r * c.r) == 0)
			break ;
		z.r = cos(z.r) * cosh(z.i) + c.i / tmp2 * -1;
		z.i = -(sin(tmp) * sinh(z.i)) + c.r / tmp2 * -1;
		i++;
		if (z.r * z.r + z.i * z.i < 250. && i < fractol->iteration)
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

void		init_batman(t_fractol *fractol)
{
	fractol->zoom = (t_zoom){250, 1.4, 1.4};
	fractol->iteration = 40;
	fractol->run = run;
	fractol->init = init_batman;
	fractol->colors.c[0] = GREEN;
	fractol->colors.c[1] = YELLOW;
	fractol->colors.c[2] = RED;
	fractol->colors.c[3] = RED;
	fractol->fractal_name = "Batman";
	fractol->fractal_equation = "cos(z) + 1 / c";
	draw_title(fractol);
	run(fractol);
}
