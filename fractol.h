/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:03:47 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/15 02:33:51 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <pthread.h> 
# include <math.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# define FRACTOL_H
# define WIN_WIDTH 1000
# define WIN_HIEGHT 700
# define MENU_WIDTH 300  
# define MAX_THREAD 100

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

typedef struct	s_argb
{
	unsigned int	a:8;
	unsigned int	r:8;
	unsigned int	g:8;
	unsigned int	b:8;
}				t_argb;

typedef union u_color
{
	t_argb argb;
	int color;
}				t_color;


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
	double scale;
	double x;
	double y;
}				t_zoom;

typedef struct	s_fractol
{
    void	*mlx_ptr;
    void	*win_ptr;
	void (*run)(struct s_fractol  *arg);
	void (*init)(struct s_fractol  *arg);
    t_img	img;
    int		iteration;
	t_zoom		zoom;
	int iteration_max;
	int img_width;
	int img_height;
	int x_thread;
	int y_thread;
	int fractal;
	int multibrot_pow;
	t_complex julia_const;
	_Bool pause;
}				t_fractol;

typedef struct	s_thread_arg
{
	t_fractol *fractol;
	int x;
	int x_max;
}				t_thread_arg;

void	put_pixel(t_img *img, int x, int y, t_argb color);
void	render(t_fractol *fractol);
void	draw_line(t_fractol *fdf, t_point p1, t_point p2, int color);
void	clean_img(t_img *img);
t_argb        ft_color1( int n, int imax);
t_argb        ft_color2(int    n, int k);



void	attach_hooks(t_fractol *fractol);
void	zoom(int button, int x, int y, t_fractol *fractol);

void	init_brot(t_fractol *fractol);
void	init_julia(t_fractol *fractol);
void	init_multibrot(t_fractol *fractol);
void	init_burning_ship(t_fractol *fractol);
void	init_tricorn(t_fractol *fractol);
void	init_feigenbaum(t_fractol *fractol);
void	init_eyebrot(t_fractol *fractol);
void	init_fractal(t_fractol *fractol);


#endif
