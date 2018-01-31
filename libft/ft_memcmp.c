/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:54:11 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/28 15:11:15 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}
