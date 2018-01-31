/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specificator_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:57:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/19 16:57:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	parse_width(t_specinfo *info, char *str, int len, va_list *args)
{
	int	tmp;

	while (--len >= 0)
		if (ft_isdigit(*(str + len)) || *(str + len) == '*')
		{
			if (*(str + len) == '*' && *(str + len - 1) != '.')
			{
				tmp = va_arg(*args, int);
				info->width = (info->width == -1) ? tmp : info->width;
				if (info->width < 0)
				{
					info->zero_minus = '-';
					info->width *= -1;
				}
				break ;
			}
			while (len >= 0 && (ft_isdigit(*(str + len - 1))))
				len--;
			if (*(str + len - 1) != '.')
			{
				tmp = ft_atoi(str + len);
				if (tmp > info->width)
					info->width = tmp;
			}
		}
}

static void	parse_precision(t_specinfo *info, char *str, int len, va_list *args)
{
	while (--len >= 0)
		if (*(str + len) == '.')
		{
			info->precision = (*(str + len + 1) == '*') ?
							va_arg(*args, int) : ft_atoi((str + len + 1));
			if (info->precision < 0)
				info->precision = -1;
			break ;
		}
}

static void	parse_mods_and_flags(t_specinfo *info, char *str, int len)
{
	while (--len >= 0)
	{
		if (*(str + len) == 'h')
			info->mod_h += 1;
		else if (*(str + len) == 'l')
			info->mod_l += 1;
		else if (*(str + len) == 'j')
			info->mod_j += 1;
		else if (*(str + len) == 'z')
			info->mod_z += 1;
		else if (*(str + len) == 'L')
			info->mod_l_up += 1;
		else if (*(str + len) == '-')
			info->zero_minus = '-';
		else if (*(str + len) == '0' && info->zero_minus != '-' &&
				!(ft_isdigit(*(str + len - 1))))
			info->zero_minus = '0';
		else if (*(str + len) == '+')
			info->plus_space = '+';
		else if (*(str + len) == ' ' && info->plus_space != '+')
			info->plus_space = ' ';
		else if (*(str + len) == '#')
			info->sharp = '#';
	}
}

static void	get_specificator_format(char *str, int *pos, t_specinfo *info)
{
	char	c;

	while (*(str + *pos))
	{
		c = *(str + *pos);
		if (ft_chrin_str(FORMAT, c))
		{
			info->format = *(str + *pos);
			break ;
		}
		if (!ft_isdigit(c) && c != '.' && !(ft_chrin_str(FLAG, c)) &&
				!(ft_chrin_str(MOD, c)) && c != '*')
			break ;
		(*pos)++;
	}
}

void		specificator_manager(char **format, int *len, va_list *args)
{
	int			pos;
	t_specinfo	info;

	ft_specinfo_init(&info);
	pos = 1;
	get_specificator_format(*format, &pos, &info);
	parse_width(&info, *format + 1, pos - 1, args);
	parse_precision(&info, *format + 1, pos - 1, args);
	parse_mods_and_flags(&info, *format + 1, pos - 1);
	if (!(info.format))
	{
		if (*(*format + pos) != '\0')
		{
			format_c_putchar(&info, len, *(*format + pos));
			pos++;
		}
		*format += pos;
		return ;
	}
	print_manager(&info, len, args);
	*format += pos + 1;
}
