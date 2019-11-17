/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:51:00 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/17 07:09:54 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractol *fractol)
{
	if (fractol->fractal == 1)
		init_julia(fractol);
	else if (fractol->fractal == 2)
		init_multibrot(fractol);
	else if (fractol->fractal == 3)
		init_burning_ship(fractol);
	else if (fractol->fractal == 4)
		init_tricorn(fractol);
	else if (fractol->fractal == 5)
		init_feigenbaum(fractol);
	else if (fractol->fractal == 6)
		init_batman(fractol);
	else if (fractol->fractal == 7)
		init_newton(fractol);
	else
		init_brot(fractol);
	draw_colors(fractol);
}

int		main(int ac, char *av[])
{
	t_fractol	fractol;
	t_img		img;

	if (ac != 2 || !BETWEEN((fractol.fractal = ft_atoi(av[1])), 0, 7))
	{
		ft_printf("%s%s%s", USAGE, USAGE2, "7 : Julia ^ 3\n");
		return (0);
	}
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, 1000, 700, "Fractol");
	img.ptr = mlx_new_image(fractol.mlx_ptr, WIN_WIDTH - MENU_WIDTH, 700);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endn);
	attach_hooks(&fractol);
	fractol.img = img;
	fractol.x_thread = ((WIN_WIDTH - MENU_WIDTH) / MAX_THREAD);
	fractol.colors.i = 0;
	fractol.color = ft_color0;
	fractol.color_mod = 0;
	draw_menu(&fractol);
	init_fractal(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
