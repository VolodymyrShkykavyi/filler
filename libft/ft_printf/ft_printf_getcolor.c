/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getcolor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/26 16:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_printf_saveclor(char **str, char **res, short close)
{
	if (ft_strncmp(*str + 1, "eoc", close - 1) == 0)
		*res = "\033[0m";
	else if (ft_strncmp(*str + 1, "black", close - 1) == 0)
		*res = "\033[30m";
	else if (ft_strncmp(*str + 1, "red", close - 1) == 0)
		*res = "\033[31m";
	else if (ft_strncmp(*str + 1, "green", close - 1) == 0)
		*res = "\033[32m";
	else if (ft_strncmp(*str + 1, "yellow", close - 1) == 0)
		*res = "\033[33m";
	else if (ft_strncmp(*str + 1, "blue", close - 1) == 0)
		*res = "\033[34m";
	else if (ft_strncmp(*str + 1, "cyan", close - 1) == 0)
		*res = "\033[36m";
	else if (ft_strncmp(*str + 1, "white", close - 1) == 0)
		*res = "\033[37m";
}

void		ft_printf_getcolor(char **str, int *len)
{
	char	*res;
	short	close;

	close = 0;
	while (*(*str + close) != '}' && close < 10)
		close++;
	if (close == 10 || close < 4)
		return ;
	res = NULL;
	ft_printf_saveclor(str, &res, close);
	if (res == NULL)
		return ;
	ft_putstr(res);
	*len += ft_strlen(res);
	*str += close + 1;
}
