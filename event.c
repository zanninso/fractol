/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:43:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/26 01:18:01 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5 || button == 4)
		zoom(button, x, y, fractol);
	if (button == 1)
	{
		color_select(x, y, fractol);
		color_slide(x, y, fractol);
		fractol->left_button_pressed = 1;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_fractol *fractol)
{
	x += y * 0;
	if (button == 1)
		fractol->left_button_pressed = 1;
	return(1);
}

static int	move(int x, int y, t_fractol *fractol)
{
	if (!fractol->pause)
	{
		x -= MENU_WIDTH;
		fractol->julia_const.r = (double)(x - 350) / 90.;
		fractol->julia_const.i = (double)(y - 350) / 90.;
		fractol->run(fractol);
	}
	if (fractol->left_button_pressed)
		color_slide(x, y, fractol);
	return (0);
}

int		key_press(int button, t_fractol *fractol)
{
	if (button == 49)
		fractol->pause ^= 1;
	else if (button == 43 || button == 47)
	{
		fractol->fractal = (fractol->fractal + (button == 47 ? 1 : 7)) % 8;
		init_fractal(fractol);
	}
	else if (button == 8)
		change_color_mod(fractol);
	else if (button == 15)
		fractol->init(fractol);
	else if (button == 69 || (button == 78 && fractol->iteration >= 10))
	{
		fractol->iteration += button == 69 ? 10 : -10;
		fractol->run(fractol);
	}
	if (BETWEEN(button, 123, 126))
		fractal_move(button, fractol);
	else if (button == 53)
		free_and_exit(fractol);
	return (0);
}

int		win_close(t_fractol *fractol)
{
	free_and_exit(fractol);
	return (0);
}

void	attach_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 2, 1, key_press, fractol);
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 5, 1, mouse_release, fractol);
	mlx_hook(fractol->win_ptr, 6, 1, move, fractol);
	mlx_hook(fractol->win_ptr, 17, 1, win_close, fractol);
}
