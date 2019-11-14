/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:43:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/14 04:14:21 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_press(int button, int x, int y, t_fractol *fractol)
{
	double old_zoom;

	if (button == 5 || button == 4)
	{
		x -= MENU_WIDTH;
		old_zoom = fractol->zoom.zoom;
		fractol->zoom.zoom *= button == 5 ? 1.1 : 0.7;
		fractol->zoom.x += x / fractol->zoom.zoom - x / old_zoom;
		fractol->zoom.y += y / fractol->zoom.zoom - y / old_zoom;
		fractol->iteration += button == 5 ? 3 : -3;
		run(fractol);
		render(fractol);
	}
	return (0);
}

int mouse_move(int x, int y, t_fractol *fractol)
{
	ft_printf("r : %Lf i : %Lf\n",fractol->julia_const.r,fractol->julia_const.i);
	x -= MENU_WIDTH;
	fractol->julia_const.r += (double)(x - fractol->x) / 700.;
	fractol->julia_const.i += (double)(y - fractol->y) / 700.;
	fractol->x = x;
	fractol->y = y;
	run(fractol);
	render(fractol);
	return (0);
}

void attach_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	// mlx_hook(fdf->win_ptr, 5, 1, mouse_release, fdf);
	mlx_hook(fractol->win_ptr, 6, 1, mouse_move, fractol);
	// mlx_hook(fdf->win_ptr, 2, 1, key_press, fdf);
}
