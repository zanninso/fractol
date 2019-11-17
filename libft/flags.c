/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:32:07 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/09/19 22:20:59 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_bit(long long *op, int n)
{
	long long b;

	b = 1;
	b <<= n;
	*op |= b;
}

_Bool		ft_set_flags(char *str, long long *flags)
{
	int n;

	if (!str || *str++ != '-' || !ft_isalnum(*str))
		return (0);
	while (*str)
	{
		if (!ft_isalnum(*str))
		{
			ft_putendl("koko");
			continue;
		}
		n = 48 + (!ft_isdigit(*str) * 7) + ((*str >= 'a' && *str <= 'z') * 6);
		put_bit(flags, (*str - n));
		str++;
	}
	return (1);
}

_Bool		ft_flag_is_active(char c, long long flags)
{
	int n;

	n = 48 + (!ft_isdigit(c) * 7) + ((c >= 'a' && c <= 'z') * 6);
	return ((flags >> (c - n)) & 1);
}
