/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:03:47 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/18 07:04:15 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "mlx.h"
# include "define.h"
# include "libft/includes/libft.h"

typedef struct	s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_argb
{
	unsigned int	b:8;
	unsigned int	g:8;
	unsigned int	r:8;
}				t_argb;

typedef union	u_rgb_color
{
	int			c;
	t_argb		rgb;
}				t_rgb_color;

typedef struct	s_color
{
	int			i;
	int			*c;
}				t_color;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endn;
}				t_img;

typedef struct	s_zoom
{
	double		scale;
	double		x;
	double		y;
}				t_zoom;

typedef struct	s_fractol
{
	t_argb		(*color)(int i, int imax, struct s_fractol *arg);
	void		(*run)(struct s_fractol *arg);
	void		(*init)(struct s_fractol *arg);
	void		*mlx_ptr;
	void		*win_ptr;
	char		*fractal_name;
	char		*fractal_equation;
	t_color		colors;
	t_complex	julia_const;
	t_img		img;
	t_zoom		zoom;
	int			iteration;
	int			iteration_max;
	int			img_width;
	int			img_height;
	int			x_thread;
	int			y_thread;
	int			fractal;
	int			color_mod;
	_Bool		pause;
}				t_fractol;

typedef struct	s_thread_arg
{
	t_fractol	*fractol;
	int			x;
	int			x_max;
}				t_thread_arg;

void			put_pixel(t_img *img, int x, int y, t_argb color);
void			render(t_fractol *fractol);
void			draw_rectangle(t_point p1, t_point p2, int color, t_fractol *f);
void			draw_menu(t_fractol *fractol);
void			draw_colors_selector(t_fractol *fractol);
void			draw_colors(t_fractol *fractol);
void			draw_title(t_fractol *fractol);
void			draw_zoom_iteration(t_fractol *fractol);

t_argb			ft_color1(int i, int iteration, t_fractol *fractol);
t_argb			ft_color2(int i, int iteration, t_fractol *fractol);
t_argb			ft_color0(int i, int iteration, t_fractol *fractol);
void			change_color_mod(t_fractol *fractol);

void			attach_hooks(t_fractol *fractol);
void			zoom(int button, int x, int y, t_fractol *fractol);
void			color_select(int x, int y, t_fractol *fractol);
void			color_slide(int x, int y, t_fractol *fractol);
void			fractal_move(int button, t_fractol *fractol);

void			init_brot(t_fractol *fractol);
void			init_julia(t_fractol *fractol);
void			init_multibrot(t_fractol *fractol);
void			init_burning_ship(t_fractol *fractol);
void			init_tricorn(t_fractol *fractol);
void			init_feigenbaum(t_fractol *fractol);
void			init_batman(t_fractol *fractol);
void			init_newton(t_fractol *fractol);

void			init_fractal(t_fractol *fractol);
void			free_and_exit(t_fractol *fracol);

#endif
