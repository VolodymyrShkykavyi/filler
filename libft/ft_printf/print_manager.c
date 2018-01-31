/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:32:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 13:32:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_manager(t_specinfo *info, int *len, va_list *args)
{
	if (info->format == 's' || info->format == 'S')
		format_s(info, len, args);
	else if (info->format == 'c' || info->format == 'C')
		format_c(info, len, args);
	else if (info->format == 'd' || info->format == 'D' || info->format == 'i')
		format_d_i(info, len, args);
	else if (info->format == 'n')
		format_n(info, len, args);
	else if (info->format == 'o' || info->format == 'O')
		format_o(info, len, args);
	else if (info->format == 'x' || info->format == 'X')
		format_x(info, len, args);
	else if (info->format == 'p')
		format_p(info, len, args);
	else if (info->format == 'u' || info->format == 'U')
		format_u(info, len, args);
	else if (info->format == 'b')
		format_b(info, len, args);
	else
		va_arg(*args, int);
}
