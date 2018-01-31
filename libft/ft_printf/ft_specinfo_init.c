/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specinfo_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:59:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/12 13:59:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specinfo_init(t_specinfo *info)
{
	info->format = 0;
	info->zero_minus = 0;
	info->plus_space = 0;
	info->sharp = 0;
	info->width = -1;
	info->precision = -1;
	info->mod_h = 0;
	info->mod_j = 0;
	info->mod_l = 0;
	info->mod_z = 0;
	info->mod_l_up = 0;
}
