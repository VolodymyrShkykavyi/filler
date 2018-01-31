/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:16:33 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/31 16:41:08 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	res;
	char	*str;
	char	*start;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	start = str;
	while (*s)
	{
		res = f(*s);
		if (res)
		{
			*str = res;
			str++;
		}
		s++;
	}
	*str = '\0';
	return (start);
}
