/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:12:41 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/09 20:47:01 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# include "../fractol.h"
# define MANDELBROT_H

typedef struct s_mandelbrot
{
long double x1;
long double x2;
long double y1;
long double y2;
int zoom;// pour une distance de 1 sur le plan, on a 100 pixel sur l'image
int iteration_max;
int img_width;
int img_height;
} t_mandelbrot;

#endif
