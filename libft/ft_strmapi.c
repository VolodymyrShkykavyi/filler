/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:39:31 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/02 14:50:54 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	char	c;
	char	*start;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	start = str;
	while (s[i])
	{
		c = f(i, s[i]);
		if (c)
			*(str++) = c;
		i++;
	}
	*str = '\0';
	return (start);
}
