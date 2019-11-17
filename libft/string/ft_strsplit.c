/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:03:34 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TR(c,v) (c >= 0 ? c : v)

char	**ft_strsplit(char const *s, char c)
{
	int		size;
	int		i;
	char	**tab2d;

	if (!s)
		return (0);
	tab2d = NULL;
	i = 0;
	size = ft_wordcount(s, c);
	tab2d = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab2d)
		return (0);
	while (size--)
	{
		s = ft_skipchr(s, c);
		tab2d[i++] = ft_strsub(s, 0, TR(ft_strindexof(s, c), ft_strlen(s)));
		s = ft_skipnchr(s, ft_strindexof(s, c));
	}
	tab2d[i] = 0;
	return (tab2d);
}
