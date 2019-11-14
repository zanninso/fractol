/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/14 22:00:16 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_fractol *fractol)
{
	if(fractol->fractal == 1)
		init_julia(fractol);
	else if(fractol->fractal == 2)
		init_multibrot(fractol);
	else if(fractol->fractal == 3)
		init_burning_ship(fractol);
	else if(fractol->fractal == 4)
		init_tricorn(fractol);
	else
		init_brot(fractol);
}

int main()
{
	t_fractol fractol;

	t_img img;
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, WIN_WIDTH, WIN_HIEGHT, "mlx");
	img.ptr = mlx_new_image(fractol.mlx_ptr, WIN_WIDTH - MENU_WIDTH, WIN_HIEGHT);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	attach_hooks(&fractol);
	fractol.img = img;
	fractol.x_thread = ((WIN_WIDTH - MENU_WIDTH) / MAX_THREAD);
	fractol.fractal = 0;
	init_brot(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
