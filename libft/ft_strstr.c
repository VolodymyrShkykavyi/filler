/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:19:28 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/31 13:46:54 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	nlen;
	size_t	hlen;
	size_t	find;

	if (!(*needle))
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen > hlen)
		return (NULL);
	i = 0;
	while (i <= hlen - nlen)
	{
		find = 0;
		j = 0;
		while ((needle[j] == haystack[i + j]) && needle[j++])
			find++;
		if (find == nlen)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
