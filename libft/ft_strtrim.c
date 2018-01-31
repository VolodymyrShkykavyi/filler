/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:07:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/02 14:44:53 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	long	i;
	long	end;
	char	*start;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	end = ft_strlen(s);
	while ((s[--end] == ' ' || s[end] == '\n' || s[end] == '\t') && end >= i)
		;
	str = (char *)malloc(sizeof(char) * (end - i + 1) + 1);
	if (str == NULL)
		return (NULL);
	start = str;
	while (i <= end)
		*(str++) = s[i++];
	*str = '\0';
	return (start);
}
