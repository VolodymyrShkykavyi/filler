/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:00:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 13:00:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static short	ft_uitoa_numlen(uintmax_t num, short base)
{
	short	len;

	len = (num == 0) ? 1 : 0;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

char			*ft_uitoa_base(uintmax_t num, short base)
{
	char	*res;
	short	len;

	len = ft_uitoa_numlen(num, base);
	if (base < 2 || base > 16 ||
		!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[len--] = HEX_SYMBOLS[num % base];
		num /= base;
	}
	return (res);
}
