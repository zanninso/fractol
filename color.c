/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:30:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/18 07:10:00 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_mod(t_fractol *fractol)
{
	fractol->color_mod = (fractol->color_mod + 1) % 3;
	if (fractol->color_mod == 0)
		fractol->color = ft_color0;
	else if (fractol->color_mod == 1)
		fractol->color = ft_color1;
	else
		fractol->color = ft_color2;
	fractol->run(fractol);
}

t_argb	color(int color1, int color2, double percent)
{
	t_argb				rgb;
	const t_rgb_color	c1 = (t_rgb_color){color1};
	const t_rgb_color	c2 = (t_rgb_color){color2};

	rgb.r = c1.rgb.r * percent + c2.rgb.r * (1. - percent);
	rgb.g = c1.rgb.g * percent + c2.rgb.g * (1. - percent);
	rgb.b = c1.rgb.b * percent + c2.rgb.b * (1. - percent);
	return (rgb);
}

t_argb	ft_color1(int i, int iteration, t_fractol *fractol)
{
	t_rgb_color color;
	double		t;

	color.c = fractol->colors.c[0];
	t = i + (double)iteration * 0.089;
	color.rgb.b = t * 59;
	color.rgb.r = ((color.rgb.b - (int)t) * color.rgb.r) + 50;
	color.rgb.g = color.rgb.r * color.rgb.g + 100;
	return (color.rgb);
}

t_argb	ft_color2(int n, int k, t_fractol *fractol)
{
	int			x;
	t_rgb_color	color;
	t_argb		rgb;

	color.c = fractol->colors.c[0];
	rgb = color.rgb;
	x = (n / (k / 6));
	if (x == 0)
		return ((t_argb){rgb.r, (n % (k / 6)) * (rgb.g / (k / 6)), 0});
	if (x == 1)
		return ((t_argb){rgb.r - n % (k / 6) * (rgb.r / (k / 6)), rgb.g, 0});
	if (x == 2)
		return ((t_argb){0, rgb.g, (n % (k / 6)) * (rgb.b / (k / 6))});
	if (x == 3)
		return ((t_argb){0, rgb.g - (n % (k / 6)) * (rgb.g / (k / 6)), 0});
	if (x == 4)
		return ((t_argb){(n % (k / 6)) * (rgb.r / (k / 6)), 0, rgb.b});
	if (x == 5)
		return ((t_argb){rgb.r, 0, rgb.b - n % (k / 6) * (rgb.b / (k / 6))});
	return ((t_argb){0, 0, 0});
}

t_argb	ft_color0(int i, int iteration, t_fractol *fractol)
{
	double			x;
	double			*tab;
	const double	n = (double)i;

	if (i == iteration)
		return ((t_argb){0, 0, 0});
	x = (double)iteration / 4.;
	x == 0 ? x = 55 : 0;
	tab = (double[2]){x * 2, x * 3};
	if (BETWEEN(i, 0, x))
		return (color(fractol->colors.c[1], fractol->colors.c[0], n / x));
	else if (BETWEEN(i, x, tab[0]))
	{
		return (color(fractol->colors.c[2], fractol->colors.c[1], (n - x) / x));
	}
	else if (BETWEEN(i, tab[0], tab[1]))
		return (color(fractol->colors.c[3], fractol->colors.c[2],
															(n - tab[0]) / x));
	else
		return (color(0xffffff, fractol->colors.c[3], (n - tab[1]) / x));
}
