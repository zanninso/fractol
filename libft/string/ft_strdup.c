/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:25:22 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/09/14 17:42:39 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;

	if (!str || !(s = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	return (ft_strcpy(s, str));
}
