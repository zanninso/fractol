/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:43:36 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/14 21:59:29 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5 || button == 4 || button == 1)
		zoom(button, x, y, fractol);
	return (0);
}

int key_press(int button, t_fractol *fractol)
{
	if (button == 49)
		fractol->pause ^= 1;
	else if(button == 1)
	{
		fractol->fractal = (fractol->fractal + 1) % 5;
		init_fractal(fractol);
	}
	return (0);
}

void attach_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 2, 1, key_press, fractol);
}
