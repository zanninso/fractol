/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/12 00:11:09 by aait-ihi         ###   ########.fr       */
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
	fractol->iteration = 1;
	fractol->zoom.zoom = 1;
	fractol->zoom.x = 0;
	fractol->zoom.y = 0;
	fractol->iteration = 50 * fractol->zoom.zoom;
	//attach_hooks(fractol);
}

int main()
{
	t_fractol fractol;
	init(&fractol);
	fractol1(&fractol);
	render(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
