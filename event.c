/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:43:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/12 00:07:04 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5 || button == 4 || button == 1)
	{
		x += y * 0;
		// const int x2 = fractol->zoom.zoom * x;
		// const int y2 = fractol->zoom.zoom * y;
		x -= MENU_WIDTH;
		fractol->zoom.zoom *= button == 5 ? 1.05 : 1.05;
		fractol->zoom.x += round(x * fractol->zoom.zoom) - (x + fractol->zoom.x);
		fractol->zoom.y += round(y * fractol->zoom.zoom) - (y + fractol->zoom.y);
		ft_printf("zoom x start : %d\n",fractol->zoom.x);
		fractol1(fractol);
		render(fractol);
	}
	return (0);
}

void	attach_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	// mlx_hook(fdf->win_ptr, 5, 1, mouse_release, fdf);
	// mlx_hook(fdf->win_ptr, 6, 1, mouse_move, fdf);
	// mlx_hook(fdf->win_ptr, 2, 1, key_press, fdf);
}
