/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:14:14 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/02 17:39:49 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	*start;

	start = (unsigned long *)dst;
	if (dst < src)
	{
		while (len-- > 0)
			*((unsigned char *)dst++) = *((unsigned char *)src++);
	}
	else if (dst > src)
	{
		while (len-- > 0)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	return (start);
}
