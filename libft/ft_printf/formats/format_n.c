/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:14:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 14:14:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_n(t_specinfo *info, int *len, va_list *args)
{
	if (info->mod_h > 1)
		*(va_arg(*args, char *)) = (char)(*len);
	else if (info->mod_h == 1)
		*(va_arg(*args, short *)) = (short)(*len);
	else if (info->mod_l == 1)
		*(va_arg(*args, long *)) = (long)(*len);
	else if (info->mod_l > 1)
		*(va_arg(*args, long long *)) = (long long)(*len);
	else if (info->mod_j)
		*(va_arg(*args, intmax_t *)) = (intmax_t)(*len);
	else if (info->mod_z)
		*(va_arg(*args, size_t *)) = (size_t)(*len);
	else
		*(va_arg(*args, int *)) = (int)(*len);
}
