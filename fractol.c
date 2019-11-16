/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/16 06:17:58 by aait-ihi         ###   ########.fr       */
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
	else  if(fractol->fractal == 5)
		init_feigenbaum(fractol);
	else  if(fractol->fractal == 6)
		init_eyebrot(fractol);
	else if(fractol->fractal == 7)
		init_newton(fractol);
	else
		init_brot(fractol);
		
}

int main()
{
	t_fractol fractol;

	t_img img;
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, WIN_WIDTH, WIN_HIEGHT, "fractol");
	img.ptr = mlx_new_image(fractol.mlx_ptr, WIN_WIDTH - MENU_WIDTH, WIN_HIEGHT);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	attach_hooks(&fractol);
	fractol.img = img;
	fractol.x_thread = ((WIN_WIDTH - MENU_WIDTH) / MAX_THREAD);
	fractol.fractal = 0;
	fractol.colors = (t_color){0,(int[4]){0xffffff, 0xff0000, 0xffff00, 0x00ff00}};
	fractol.color = ft_color0;
	fractol.color_mod = 0;
	draw_menu(&fractol);
	init_brot(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
