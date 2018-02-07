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

void	alg_get_piece_startpos(t_game *game, t_alg *alg_info)
{
	int	x;
	int	y;

	x = -1;
	alg_info->piece_start.x = -1;
	alg_info->piece_start.y = -1;
	while (game->piece[++x])
	{
		y = -1;
		while (game->piece[x][++y])
		{
			if (game->piece[x][y] == '*')
			{
				if (alg_info->piece_start.x == -1)
					alg_info->piece_start.x = x;
				if (alg_info->piece_start.y == -1 ||
						alg_info->piece_start.y > y)
				{
					alg_info->piece_start.y = y;
				}
			}
		}
	}
}

void	alg_find_last_enm_pos(t_game *game, t_alg *alg)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == game->enm)
				if (game->old_map[x][y] != game->enm)
				{
					alg->enm_last.x = x;
					alg->enm_last.y = y;
					return ;
				}
		}
	}
}

void	alg_find_place_forpiece(t_game *game, t_alg *alg)
{
	t_point			pos;
	unsigned long	len;

	pos.x = -1;
	while (game->map[++pos.x])
	{
		pos.y = -1;
		while (game->map[pos.x][++pos.y])
		{
			len = len_between_points(pos, alg->enm_last);
			if (alg->enm_last_len == 0 || alg->enm_last_len > len)
			{
				if (alg_check_piece_overlap(game, alg, pos) == 1)
				{
					alg->result.x = pos.x - alg->piece_start.x;
					alg->result.y = pos.y - alg->piece_start.y;
					alg->enm_last_len = len;
				}
			}
		}
	}
}

void	algorithm(t_game *game)
{
	static t_alg	alg_info;
	char			**tmp;

	alg_info.result.y = 0;
	alg_info.result.x = 0;
	alg_info.enm_last_len = 0;
	alg_get_piece_startpos(game, &alg_info);
	if (game->old_map[0])
		alg_find_last_enm_pos(game, &alg_info);
	else
		alg_info.enm_last = game->enm_start;
	if (alg_info.enm_last.x < game->enm_start.x)
		alg_info.enm_last.x -= 2;
	else
		alg_info.enm_last.x += 2;
	if (alg_info.enm_last.y < game->enm_start.y)
		alg_info.enm_last.y -= 2;
	else
		alg_info.enm_last.y += 2;
	alg_find_place_forpiece(game, &alg_info);
	ft_printf("%d %d\n", alg_info.result.x, alg_info.result.y);
	tmp = game->map;
	game->map = game->old_map;
	game->old_map = tmp;
}
