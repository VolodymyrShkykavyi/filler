/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:22:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 13:22:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstr(wchar_t *wstr)
{
	size_t	len;

	len = 0;
	while (*wstr)
		len += ft_putwchar(*wstr++);
	return (len);
}
