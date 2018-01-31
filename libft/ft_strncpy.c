/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:36:59 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/30 17:00:36 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*start;

	start = dst;
	while (*src && len > 0)
	{
		*(dst++) = *(src++);
		len--;
	}
	while (len-- > 0)
		*(dst++) = '\0';
	return (start);
}
