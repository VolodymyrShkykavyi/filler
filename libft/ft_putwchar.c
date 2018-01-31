/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:01:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/17 16:30:34 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include <wchar.h>

/*
** UNICODE format
**
** hex max 7f:		0vvvvvvv
** hex max 7ff:		110vvvvv 10vvvvvv
** hex max ffff:	1110vvvv 10vvvvvv 10vvvvvv
** hex max 1fffff:	11110vvv 10vvvvvv 10vvvvvv 10vvvvvv
**
** 1100 0000 - 0xC0
** 1110 0000 - 0xE0
** 1111 0000 - 0xF0
** 1000 0000 - 0x80
*/

int		ft_putwchar(wchar_t wc)
{
	if (wc <= 0x7F)
		return (write(1, &wc, 1));
	else if (wc <= 0x7FF)
	{
		ft_putchar((wc >> 6) | 0xC0);
		ft_putchar((wc & 0x3F) | 0x80);
		return (2);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar((wc >> 12) | 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
		return (3);
	}
	else if (wc <= 0x1FFFFF)
	{
		ft_putchar((wc >> 18) | 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) | 0x80);
		ft_putchar(((wc >> 6) & 0x3F) | 0x80);
		ft_putchar((wc & 0x3F) | 0x80);
		return (4);
	}
	return (0);
}
