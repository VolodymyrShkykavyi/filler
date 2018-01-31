/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_toupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:10:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/10 17:10:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew_toupper(char *str)
{
	char	*new;
	char	*start;

	if (str == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	start = new;
	while (*str)
		*(new++) = ft_toupper(*(str++));
	*new = *str;
	return (start);
}
