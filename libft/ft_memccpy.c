/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:30:51 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/28 15:09:44 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		*(unsigned char *)(dest) = *(unsigned char *)(src);
		if (*(unsigned char *)dest == (unsigned char)c)
			return (dest + 1);
		dest++;
		src++;
	}
	return (0);
}
