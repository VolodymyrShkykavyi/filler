/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:09:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 14:09:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	format_b_print(t_specinfo *info, char *str,
							short str_len, short space_len)
{
	if (info->zero_minus != '-')
		ft_putnchar(' ', space_len);
	if (info->sharp)
		ft_putstr("0b");
	ft_putnchar('0', str_len - ft_strlen(str));
	ft_putstr(str);
	if (info->zero_minus == '-')
		ft_putnchar(' ', space_len);
}

void		format_b(t_specinfo *info, int *len, va_list *args)
{
	uintmax_t	num;
	char		*str;
	short		str_len;
	short		space_len;

	ft_printf_cast_unum(info, &num, args);
	str = (!num && !(info->precision)) ? ft_strnew(0) : ft_uitoa_base(num, 2);
	str_len = ft_strlen(str);
	str_len = (str_len > info->precision) ? str_len : info->precision;
	if (info->sharp && num != 0)
		str_len += 2;
	space_len = (str_len < info->width) ? info->width - str_len : 0;
	*len += space_len + str_len;
	if (info->sharp && num != 0)
		str_len -= 2;
	format_b_print(info, str, str_len, space_len);
	free(str);
}
