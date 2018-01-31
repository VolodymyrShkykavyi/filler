/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:15:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 14:15:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	format_o(t_specinfo *info, int *len, va_list *args)
{
	uintmax_t	num;
	char		*str;
	short		space_len;
	short		str_len;

	if (info->format == 'O')
		num = va_arg(*args, unsigned long);
	else
		ft_printf_cast_unum(info, &num, args);
	str = (!num && !(info->precision)) ? ft_strnew(0) : ft_uitoa_base(num, 8);
	str_len = ft_strlen(str);
	if (info->sharp && *str != '0')
		str_len++;
	str_len = (info->precision > str_len) ? info->precision : str_len;
	space_len = (info->width > str_len) ? info->width - str_len : 0;
	*len += space_len + str_len;
	if (info->zero_minus != '-')
		ft_putnchar((info->zero_minus == '0' && info->precision == -1)
					? '0' : ' ', space_len);
	ft_putnchar('0', str_len - ft_strlen(str));
	ft_putstr(str);
	if (info->zero_minus == '-')
		ft_putnchar(' ', space_len);
	free(str);
}
