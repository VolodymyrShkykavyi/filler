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
/*
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
*/

/*
** check enemy a nearest 4 points
*/

char	alg_check_enemy_reached(t_game *game, t_alg *alg_info)
{
	int x;
	int	y;
	int	offset;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
			if (game->map[x][y] == game->plr)
			{
				offset = 4;
				while (--offset > 0)
				{
					if (x - offset > 0 && x + offset < game->map_h)
						if (game->map[x - offset][y] == game->enm
								|| game->map[x + offset][y] == game->enm)
							return ((alg_info->reached = 1));
					if (y - offset > 0 && y + offset < game->map_w)
						if (game->map[x][y - offset] == game->enm
								|| game->map[x][y + offset] == game->enm)
							return ((alg_info->reached = 1));
				}
			}
	}
	return (0);
}

short	alg_check_piece_overlap(t_game *game, t_point token)
{
	short	overlap;
	int		x;
	int 	y;

	x = -1;
	overlap = 0;
	while (game->piece[++x])
	{
		y = -1;
		while (game->piece[x][++y])
			if (game->piece[x][y] == '*')
			{
				if (token.x + x < 0 || token.x + x >= game->map_h ||
						token.y + y < 0 || token.y + y >= game->map_w)
					return (0);
				if (game->map[token.x + x][token.y + y] == game->plr)
					overlap++;
			}
	}
	return (overlap);
}

short	alg_check_piece_placing(t_game *game, t_point pos, t_alg *alg)
{
	int 	x;
	int 	y;
	t_point	map_token;

	x = -1;
	while (game->piece[++x])
	{
		y = -1;
		while (game->piece[x][++y])
			if (game->piece[x][y] == '*')
			{
				map_token.x = pos.x /*- x*/;
				map_token.y = pos.y /*- y*/;
				if (alg_check_piece_overlap(game, map_token) == 1)
				{
					dprintf(2, "check %d %d\n", pos.x, pos.y);
					alg->result = map_token;
					return (1);
				}
				else
					return (0);
			}
	}
	return (0);
}

short	alg_reach_enemy_bott(t_game *game, t_alg *alg)
{
	t_point	pos;

	pos.x = game->map_h;
	while (--pos.x >= 0)
	{
		pos.y = game->map_w;
		while (--pos.y >= 0)
		{
			//if (alg_check_piece_placing(game, pos, alg) == 1)
			if (alg_check_piece_overlap(game, pos) == 1)
			{
				alg->result = pos;
				return (1);
			}
		}
	}
	return (0);
}

short	alg_reach_enemy_top(t_game *game, t_alg *alg)
{
	t_point	pos;

	pos.x = -1;
	while (game->map[++pos.x])
	{
		pos.y = -1;
		while (game->map[pos.x][++pos.y])
		{
			if (alg_check_piece_placing(game, pos, alg) == 1)
				return (1);
		}
	}
	return (0);
}

void	algorithm(t_game *game)
{
	static t_alg alg_info = {.reached = 0};

	alg_info.result.y = 0;
	alg_info.result.x = 0;
	if (alg_info.reached == 0)
	{
		if (alg_check_enemy_reached(game, &alg_info) == 0)
		{
			if (game->plr_start.y < game->enm_start.y)
				alg_reach_enemy_bott(game, &alg_info);
			else
				alg_reach_enemy_top(game, &alg_info);
		}
		ft_printf("%d %d\n", alg_info.result.x, alg_info.result.y);
		return ;
	}
	ft_printf("0 0\n");

	//analyze enm
	//enm_angle = alg_enemy_angle(game);
	//choose direction
	//set priority cells on map
	//find and place piece
}