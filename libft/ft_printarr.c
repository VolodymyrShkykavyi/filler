/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:02:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/10 19:02:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarr(char **arr)
{
	int		i;

	i = 0;
	if (!arr || !(*arr))
		ft_putstr_fd("empty\n", 2);
	while (arr[i])
	{
		ft_putchar_fd('[', 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("] => \"", 2);
		ft_putstr_fd(arr[i], 2);
		ft_putstr_fd("\"\n", 2);
		i++;
	}
}
