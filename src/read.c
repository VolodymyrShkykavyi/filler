/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:08:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/30 20:08:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** parsing map height and width. Then allocate memory for map.
** Example of line with map info: "Plateau 15 17:"
*/

int 	init_map(t_game *game, char **line)
{
	char	**arr;
	int 	height;

	if (!(arr = ft_strsplit(*line, ' ')))
		return (1);
	game->map_h = ft_atoi(arr[1]);
	game->map_w = ft_atoi(arr[2]);
	ft_free_2arr(arr);
	ft_strdel(line);
	height = game->map_h;
	if (!(game->map = (char**)malloc(sizeof(char*) * (height + 1))))
		return (1);
	game->map[height] = NULL;
	if (!(game->old_map = (char**)malloc(sizeof(char*) * (height + 1))))
		return (1);
	game->old_map[height] = NULL;
	while (--height >= 0)
	{
		if (!(game->map[height] = ft_strnew(game->map_w)))
			return (1);
		if (!(game->old_map[height] = ft_strnew(game->map_w)))
			return (1);
	}
	//dprintf(2, "eof init map\n");
	return (0);
}

/*
** save all map. If start enemy and player positions aren't saved yet - just DO IT!
*/

void	read_map(t_game *game, char **line)
{
	char	**arr;
	int 	i;

	i = -1;
	//dprintf(2, "start reading map\n");
	while (++i < game->map_h)
	{
		if (!(arr = ft_strsplit(*line, ' ')))
			return ;
		ft_strcpy(game->map[i], arr[1]);
		ft_free_2arr(arr);
		ft_strdel(line);
		if (!(get_next_line(0, line)))
			return ;
		if (ft_isdigit((*line)[0]) == 0)
			return ;
	}
}

void	read_piece(t_game *game, char **line)
{
	char	**arr;
	int		i;

	if (!(arr = ft_strsplit(*line,' ')))
		return ;
	game->piece_h = ft_atoi(arr[1]);
	game->piece_w = ft_atoi(arr[2]);
	ft_free_2arr(arr);
	ft_strdel(line);
	if (!(game->piece = (char**)malloc(sizeof(char*) * (game->piece_h + 1))))
		return ;
	game->piece[game->piece_h] = NULL;
	i = -1;
	while (++i < game->piece_h)
	{
		if (!(get_next_line(0, line)))
			return ;
		if (!(game->piece[i] = ft_strdup(*line)))
			return ;
		ft_strdel(line);
	}
}
