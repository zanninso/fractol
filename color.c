/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:30:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/15 17:33:22 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_argb        ft_color1( int n, int imax)
{
    //int        tab[3];
    int        nn;
    // double    t;

    // t = (double) n / (double) imax;
    // n = (int) (t * (1677.0)); //256*256*256
    // tab[2] = n / (65536); // 256 * 256
    // nn = n - tab[2] * 65536;
    // tab[0] = nn / 256;
    // tab[1] = nn - tab[0] * 256;
    if(n == imax)
        return ((t_argb){0, 0, 0, 0});
    nn = 0x0ff700 * n * n;
    return ((t_argb){0, nn >> 16 & 255, nn >> 8 & 255, nn & 255});
}

t_argb        ft_color2(int    n, int k)
{
    int        x;

    x = (n / (k / 6));
    if (x == 0)
        return ((t_argb){0, 255, (n % (k / 6)) * (255 / (k / 6)), 0});
    if (x == 1)
        return ((t_argb){0, 255 - (n % (k / 6)) * (255 / (k / 6)), 255, 0});
    if (x == 2)
        return ((t_argb){0, 0, 255, (n % (k / 6)) * (255 / (k / 6))});
    if (x == 3)
        return ((t_argb){0, 0, 255 - (n % (k / 6)) * (255 / (k / 6)), 0});
    if (x == 4)
        return ((t_argb){0, (n % (k / 6)) * (255 / (k / 6)), 0, 255});
    if (x == 5)
        return ((t_argb){0, 255, 0, 255 - (n % (k / 6)) * (255 / (k / 6))});
    return ((t_argb){0,0,0,0});
}