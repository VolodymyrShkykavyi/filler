/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 00:24:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/01 00:24:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_point	alg_find_enemy(t_game *game)
{
	int		x;
	int 	y;
	t_point	pos;

	x = -1;
	pos.x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
			if (game->map[x][y] == ft_tolower(game->enm))
			{
				pos.x = x;
				pos.y = y;
				if (x > 0 && x < game->map_h && y > 0 && y < game->map_w)
					if (game->map[x - 1][y] == game->enm ||
							game->map[x + 1][y] == game->enm ||
							game->map[x][y - 1] == game->enm ||
							game->map[x][y + 1] == game->enm)
						return (pos);
			}
	}
	if (pos.x == -1)
		return (game->enm_start);
	return (pos);
}

short	alg_enemy_angle(t_game *game)
{
	t_point		enm_pos;
	double		angle_rad;

	enm_pos = alg_find_enemy(game);
	angle_rad =
	//math

}

void	algorithm(t_game *game)
{
	short	enm_angle;

	//analyze enm
	enm_angle = alg_enemy_angle(game);
	//choose direction
	//set priority cells on map
	//find and place piece
}