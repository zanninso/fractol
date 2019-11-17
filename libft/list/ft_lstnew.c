/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:40:55 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/06/19 22:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->content = content ? malloc((size + 1)) : 0;
	lst->content = content ? ft_memcpy(lst->content, content, size + 1) : 0;
	lst->content_size = content ? size : 0;
	lst->next = NULL;
	return (lst);
}
