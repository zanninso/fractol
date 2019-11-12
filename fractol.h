/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:03:47 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/11 22:15:52 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <math.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# define FRACTOL_H
# define WIN_WIDTH 1000
# define WIN_HIEGHT 700
# define MENU_WIDTH 300

typedef struct	s_draw_line
{
	double		diff;
	int			dx;
	int			dy;
	char		sign_dx;
	char		sign_dy;
}				t_draw_line;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_zoom
{
	double zoom;
	int x;
	int y;
}				t_zoom;

typedef struct	s_fractol
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_img	img;
    int		iteration;
	long double x1;
	long double x2;
	long double y1;
	long double y2;
	long double zoom_x;
	long double zoom_y;
	t_zoom		zoom;
	int iteration_max;
	int img_width;
	int img_height;
}				t_fractol;

typedef struct  s_complex
{
    long double r;
    long double i;
}               t_complex;

typedef struct	s_point
{
	int x;
	int y;
}	t_point;

void	put_pixel(t_img *img, int x, int y, int color);
void	fractol1(t_fractol *fractol);
void	render(t_fractol *fractol);
void	attach_hooks(t_fractol *fractol);
void		draw_line(t_fractol *fdf, t_point p1, t_point p2, int color);

#endif
