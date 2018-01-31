/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:02:07 by vshkykav          #+#    #+#             */
/*   Updated: 2017/11/01 13:21:13 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

static int	words_num(char const *s, char c)
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	if (s[i] != c && s[i])
	{
		num++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			num++;
		i++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		words;
	char	**arr;

	if (s == NULL)
		return (NULL);
	words = words_num(s, c);
	arr = (char **)malloc(sizeof(char *) * words + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (words-- > 0)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		arr[i++] = ft_strsub(s, 0, len);
		s += len;
	}
	arr[i] = NULL;
	return (arr);
}
