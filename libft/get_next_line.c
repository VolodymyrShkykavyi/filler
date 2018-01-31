/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:26:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/13 20:59:08 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_linelen(char *str, int *end)
{
	size_t len;

	len = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			*end = 1;
			return (len);
		}
		len++;
		str++;
	}
	return (len);
}

t_file	*ft_find_fd(t_file **file, const int fd, char **line)
{
	t_file	*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			*line = ft_strnew(0);
			return (tmp);
		}
		tmp = tmp->next;
	}
	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = *file;
	tmp->fd = fd;
	tmp->count = 0;
	*file = tmp;
	*line = ft_strnew(0);
	return (tmp);
}

int		ft_rewrite(t_file *curr, char **line, int *end)
{
	size_t	len;
	char	*prev_line;

	len = ft_linelen(curr->buff + curr->count, end);
	prev_line = *line;
	if (!(*line = (char *)malloc(len + ft_strlen(*line) + 1)))
	{
		free(prev_line);
		return (-1);
	}
	ft_strcpy(*line, prev_line);
	ft_strncat(*line, curr->buff + curr->count, len);
	if (curr->count >= BUFF_SIZE && (*end != 0 || *end != 1))
		*end = -1;
	curr->count += len + 1;
	free(prev_line);
	return (0);
}

int		ft_write_line(t_file *curr, char **line, int *end)
{
	ssize_t		tmp;

	tmp = 1;
	if (curr->count == 0 || curr->count >= BUFF_SIZE ||
			(curr->buff)[curr->count - 1] == '\0')
	{
		if (!(tmp = read(curr->fd, curr->buff, BUFF_SIZE)))
		{
			*end = 0;
			return (0);
		}
		(curr->buff)[tmp] = '\0';
		curr->count = 0;
	}
	if (tmp < 0)
		return (-1);
	if (ft_rewrite(curr, line, end) == -1)
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*list;
	t_file			*curr;
	int				end;

	if (fd < 0 || !line)
		return (-1);
	if (!(curr = ft_find_fd(&list, fd, line)))
		return (-1);
	end = -1;
	while (end == -1)
	{
		if (ft_write_line(curr, line, &end) == -1)
			return (-1);
	}
	return (end || (**line != '\0'));
}
