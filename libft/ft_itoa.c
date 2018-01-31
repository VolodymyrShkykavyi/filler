/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:24:05 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/01 15:52:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	long	tmp;
	char	*str;

	len = (n <= 0) ? 1 : 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	tmp = (n > 0) ? n : (-1 * (long)n);
	while (--len >= 0 && tmp != 0)
	{
		str[len] = tmp % 10 + '0';
		tmp /= 10;
	}
	str[len] = (len == 0 && n < 0) ? '-' : '0';
	return (str);
}
