/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_bytelen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:58:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 12:58:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_utf8_bytelen(wchar_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x1FFFFF)
		return (4);
	return (-1);
}
