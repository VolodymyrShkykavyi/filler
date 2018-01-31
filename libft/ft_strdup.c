/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:09:41 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/28 15:20:13 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	char	*start;

	len = ft_strlen(s1);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len);
	start = str;
	while (len-- > 0)
		*(str++) = *(s1++);
	*str = '\0';
	return (start);
}
