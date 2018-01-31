/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:18:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 14:18:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	format_p(t_specinfo *info, int *len, va_list *args)
{
	uintmax_t	addr;
	short		str_len;
	short		space_len;
	char		*str;

	addr = va_arg(*args, uintmax_t);
	str = (!addr && !(info->precision)) ? ft_strnew(0)
										: ft_uitoa_base(addr, 16);
	ft_str_tolower(&str);
	str_len = ft_strlen(str);
	str_len = (info->precision > str_len) ? info->precision + 2 : str_len + 2;
	space_len = (info->width > str_len) ? info->width - str_len : 0;
	*len += space_len + str_len;
	info->sharp = 1;
	format_x_print(info, str, str_len - 2, space_len);
	free(str);
}
