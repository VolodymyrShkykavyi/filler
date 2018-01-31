/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:57:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 12:57:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrsize(wchar_t *str)
{
	size_t	size;

	size = 0;
	while (*str)
		size += ft_utf8_bytelen(*str++);
	return (size);
}
