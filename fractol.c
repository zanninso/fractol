/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/13 22:00:39 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init(t_fractol *fractol)
{
	t_img img;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, WIN_WIDTH, WIN_HIEGHT, "mlx");
	img.ptr = mlx_new_image(fractol->mlx_ptr, WIN_WIDTH - MENU_WIDTH, WIN_HIEGHT);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	attach_hooks(fractol);
	fractol->img = img;
	fractol->zoom = (t_zoom){250, 2.2, 1.4};
	fractol->iteration = 50;
	fractol->x_thread =  ((WIN_WIDTH - MENU_WIDTH) / MAX_THREAD);
	fractol->y_thread = (WIN_HIEGHT / MAX_THREAD);
}

int main()
{
	t_fractol fractol;
	init(&fractol);
	run(&fractol);
	render(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
