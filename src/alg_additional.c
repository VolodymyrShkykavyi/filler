/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_additional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:42:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/05 15:42:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

unsigned long	len_between_points(t_point p1, t_point p2)
{
	unsigned long	len;

	len = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	return (len);
}

short			alg_check_piece_overlap(t_game *game, t_alg *alg, t_point pos)
{
	short	x;
	short	y;
	short	overlap;

	overlap = 0;
	x = alg->piece_start.x - 1;
	pos.x -= alg->piece_start.x;
	pos.y -= alg->piece_start.y;
	while (game->piece[++x])
	{
		y = alg->piece_start.y - 1;
		while (game->piece[x][++y])
		{
			if (game->piece[x][y] == '*')
			{
				if (pos.x + x >= game->map_h || pos.y + y >= game->map_w ||
					game->map[pos.x + x][pos.y + y] == game->enm)
					return (0);
				if (game->map[pos.x + x][pos.y + y] == game->plr)
					overlap++;
			}
		}
	}
	return (overlap);
}
