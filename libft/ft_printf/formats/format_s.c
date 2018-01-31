/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:19:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 14:19:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

/*
** get number of wchar that can fit in memory block
*/

static int	format_s_wstrchars_inbytes(wchar_t *str, size_t max_bytes)
{
	int		num;
	size_t	bytes;

	num = 0;
	bytes = ft_utf8_bytelen(*str);
	while (*str && bytes <= max_bytes)
	{
		num++;
		bytes += ft_utf8_bytelen(*(++str));
	}
	return (num);
}

/*
** return number of bytes( of wchars) that can fit in memory block
*/

static int	format_s_wstr_maxbytes(wchar_t *str, size_t max_bytes)
{
	int		bytes;
	size_t	tmp;

	bytes = 0;
	tmp = ft_utf8_bytelen(*str);
	while (*str && (tmp <= max_bytes))
	{
		bytes = tmp;
		tmp += ft_utf8_bytelen(*str++);
	}
	return (bytes);
}

void		format_s_putwstr(t_specinfo *info, int *len, wchar_t *str)
{
	int		str_blen;
	int		space_len;

	str_blen = ft_wstrsize(str);
	if (str_blen > info->precision && info->precision != -1)
		str_blen = format_s_wstr_maxbytes(str, info->precision);
	space_len = (str_blen < info->width) ? info->width - str_blen : 0;
	*len += space_len + str_blen;
	if (info->zero_minus == '-')
		ft_putnwstr(str, format_s_wstrchars_inbytes(str, str_blen));
	ft_putnchar((info->zero_minus == '0') ? '0' : ' ', space_len);
	if (info->zero_minus != '-')
		ft_putnwstr(str, format_s_wstrchars_inbytes(str, str_blen));
}

void		format_s_putstr(t_specinfo *info, int *len, char *str)
{
	int		str_len;
	int		space_len;

	str_len = (int)ft_strlen(str);
	if (str_len > info->precision && info->precision != -1)
		str_len = info->precision;
	space_len = (str_len < info->width) ? info->width - str_len : 0;
	*len += space_len + str_len;
	if (info->zero_minus == '-')
	{
		ft_putnstr(str, (size_t)str_len);
		ft_putnchar(' ', (size_t)space_len);
	}
	else
	{
		ft_putnchar((info->zero_minus == '0') ? '0' : ' ', space_len);
		ft_putnstr(str, (size_t)str_len);
	}
}

void		format_s(t_specinfo *info, int *len, va_list *args)
{
	char	*str;
	wchar_t	*wstr;

	if (info->format == 's' && !(info->mod_l))
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		format_s_putstr(info, len, str);
	}
	else
	{
		wstr = va_arg(*args, wchar_t*);
		if (wstr == NULL)
			wstr = L"(null)";
		format_s_putwstr(info, len, wstr);
	}
}
