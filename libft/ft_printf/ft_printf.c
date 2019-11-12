/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:11:18 by souarrak          #+#    #+#             */
/*   Updated: 2019/06/19 22:20:06 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_fmt(const char *fmt, va_list ap, va_list ap2, t_flg *flg)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '{')
			fmt = set_color(fmt);
		else if (*fmt == '%')
		{
			fmt++;
			fmt = get_options(fmt, flg, ap, ap2);
			count = count + (dispatcher(ap, flg));
		}
		else
		{
			ft_putchar_fd(*fmt, flg->w);
			count++;
			fmt++;
		}
	}
	return (count);
}

int	ft_printf(const char *restrict fmt, ...)
{
	va_list	ap;
	va_list	ap2;
	t_flg	flg;

	flg.w = 1;
	if (!fmt)
		return (0);
	va_start(ap, fmt);
	va_start(ap2, fmt);
	return (print_fmt(fmt, ap, ap2, &flg));
}
