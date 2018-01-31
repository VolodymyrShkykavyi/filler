/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cast_unum.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:29:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 13:29:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_cast_unum(t_specinfo *info, uintmax_t *num, va_list *args)
{
	if (info->mod_h > 1)
		*num = (unsigned char)va_arg(*args, uintmax_t);
	else if (info->mod_h == 1)
		*num = (unsigned short)va_arg(*args, uintmax_t);
	else if (info->mod_l == 1)
		*num = va_arg(*args, unsigned long);
	else if (info->mod_l > 1)
		*num = va_arg(*args, unsigned long long);
	else if (info->mod_j)
		*num = va_arg(*args, uintmax_t);
	else if (info->mod_z)
		*num = va_arg(*args, size_t);
	else
		*num = va_arg(*args, unsigned int);
}
