/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:00:21 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/28 15:08:32 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*start;

	start = dst;
	while (n-- > 0)
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (start);
}
