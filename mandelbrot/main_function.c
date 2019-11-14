/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:38:27 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/13 23:10:55 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

void *iterate(t_complex c, t_point p,t_fractol *fractol)
{
    int i;
    long double tmp;
    t_complex z;

    z = (t_complex){0, 0};
    i = 0;
    while (1)
    {
        tmp = z.r;
        z.r = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = 2 * z.i * tmp + c.i;
        i++;
        if (z.r * z.r + z.i * z.i < 4.0 && i < fractol->iteration)
            continue;
        break;
    }
    if (i == fractol->iteration)
        put_pixel(&fractol->img, p.x, p.y, 0);
    else
        put_pixel(&fractol->img, p.x, p.y, 0xff0100 * i);
    return(NULL);
}

void *fractol1(void *arg)
{
    int x;
    int y;
    t_complex c;
    t_fractol *fractol;

    y = 0;
    fractol = ((t_thread_arg *)arg)->fractol;
    while (y <  WIN_HIEGHT)
    {
        x = ((t_thread_arg *)arg)->x;
        while (x < ((t_thread_arg *)arg)->x_max)
        {
            c.r = x / fractol->zoom.zoom - fractol->zoom.x;
            c.i = y / fractol->zoom.zoom - fractol->zoom.y;
            iterate(c, (t_point){x,y}, fractol);
            x++;
        }
        y++;
    }
    return (NULL);
}

void run(t_fractol *fractol)
{
    int x;
    int i;
    pthread_t thread_id[MAX_THREAD];
    t_thread_arg thread_arg[MAX_THREAD];

    i = 0;
    x = 0;
    while (i < MAX_THREAD)
        {
            thread_arg[i] = (t_thread_arg){fractol, x, x + fractol->x_thread};
            pthread_create(&thread_id[i], NULL, fractol1, &thread_arg[i]);
            x += fractol->x_thread;
            i++;
        }
        while (i-- > 0)
            pthread_join(thread_id[i], NULL);
}
