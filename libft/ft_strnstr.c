/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:59:08 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/02 12:57:17 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;
	size_t	hlen;
	size_t	find;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen > hlen || len < nlen)
		return (NULL);
	while (i <= len - nlen)
	{
		find = 0;
		j = 0;
		while ((i + j < len) && (needle[j] == haystack[i + j]) && needle[j++])
			find++;
		if (find == nlen)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
