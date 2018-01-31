/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:04:21 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/02 15:56:14 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	list->content = malloc(content_size);
	if (list->content == NULL)
	{
		free(list);
		return (NULL);
	}
	ft_memcpy(list->content, content, content_size);
	list->content_size = content_size;
	return (list);
}
