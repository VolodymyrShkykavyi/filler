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
				offset = 5;
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
/*
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
*/
/*
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
				map_token.x = pos.x - x;
				map_token.y = pos.y - y;
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
*/

short	alg_check_piece_overlap(t_game *game, t_alg *alg, t_point pos)
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
				//dprintf(2, "(%c) x = %d  y = %d\n",game->plr, x, y);
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
			if (alg_check_piece_overlap(game, alg, pos) == 1)
			{
				//dprintf(2, "(%c) overlap = %d\n", game->plr, alg_check_piece_overlap(game, alg, pos));
				alg->result.x = pos.x - alg->piece_start.x;
				alg->result.y = pos.y - alg->piece_start.y;
				//dprintf(2, "(%c) pos.x =%d pos.y = %d\n", game->plr, pos.x, pos.y);
				//dprintf(2, "(%c) piece start.x =%d start.y = %d\n\n", game->plr, alg->piece_start.x, alg->piece_start.y);
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
			if (alg_check_piece_overlap(game, alg, pos) == 1)
			{
				//dprintf(2, "(%c) overlap = %d\n", game->plr, alg_check_piece_overlap(game, alg, pos));
				alg->result.x = pos.x - alg->piece_start.x;
				alg->result.y = pos.y - alg->piece_start.y;
				//dprintf(2, "(%c) rex.x =%d res.y = %d\n", game->plr, pos.x, pos.y);

				return (1);
			}
		}
	}
	return (0);
}

void	alg_get_piece_startpos(t_game *game, t_alg *alg_info)
{
	int 	x;
	int 	y;

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
					//dprintf(2, "rewrite\n");
					alg_info->piece_start.y = y;
				}
			}
		}

	}
}

void	alg_priority_change(t_game *game, t_point pos, char c, int offset)
{
	if (pos.x + offset < game->map_h)
		game->map[pos.x + offset][pos.y] = c;
	if (pos.x - offset >= 0)
		game->map[pos.x - offset][pos.y] = c;
	if (pos.y + offset < game->map_w)
		game->map[pos.x][pos.y + offset] = c;
	if (pos.y - offset >= 0)
		game->map[pos.x][pos.y - offset] = c;
}

void	alg_set_priority(t_game *game)
{
	t_point pos;

	pos.x = -1;
	while (game->map[++pos.x])
	{
		pos.y = -1;
		while (game->map[pos.x][++pos.y])
		{
			if (game->map[pos.x][pos.y] == game->enm)
			{
				alg_priority_change(game, pos, '7', 3);
				alg_priority_change(game, pos, '5', 2);
				alg_priority_change(game, pos, '3', 1);
			}
			if (pos.x == 0 || pos.y == 0)
				if (game->map[pos.x][pos.y] == '.' ||
					ft_isdigit(game->map[pos.x][pos.y]))
					game->map[pos.x][pos.y] = '9';
		}
	}
}

void	alg_find_last_enm_pos(t_game *game, t_alg *alg)
{
	int 	x;
	int 	y;

	x = -1;
	//dprintf(2, "finding last enemy\n");
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

void	algorithm(t_game *game)
{
	static t_alg	alg_info = {.reached = 0};
	char			**tmp;

	alg_info.result.y = 0;
	alg_info.result.x = 0;
	alg_get_piece_startpos(game, &alg_info);
	//dprintf(2, "start pos piece: %d %d\n", alg_info.piece_start.x, alg_info.piece_start.y);
	//dprintf(2, "start plr (%c): %d %d\n", game->plr, game->plr_start.x, game->plr_start.y);
	if (alg_info.reached == 0)
	{
		if (alg_check_enemy_reached(game, &alg_info) == 0)
		{
			if (game->plr_start.y < game->enm_start.y)
				alg_reach_enemy_bott(game, &alg_info);
			else
				alg_reach_enemy_top(game, &alg_info);
		}
		//ft_printf("%d %d\n", alg_info.result.x, alg_info.result.y);
		//return ;
	}
	//alg_set_priority(game);
	//ft_printarr(game->map);
	//exit(0);
	//ft_printf("0 0\n");
	//dprintf(2, "printing res\n");
	//return ;
	if (alg_info.reached)
	{
		if (game->old_map[0])
			alg_find_last_enm_pos(game, &alg_info);
		if (game->enm_start.x > alg_info.enm_last.x)
			alg_reach_enemy_top(game, &alg_info);
		else
			alg_reach_enemy_bott(game, &alg_info);
	}
	ft_printf("%d %d\n", alg_info.result.x, alg_info.result.y);

	//dprintf(2, "last enmy at %d %d\n", alg_info.enm_last.x, alg_info.enm_last.y);
	//dprintf(2, "before map p: %p old %p\n", game->map, game->old_map);
	tmp = game->map;
	game->map = game->old_map;
	game->old_map = tmp;
	//ft_swap(&(game->map), &(game->old_map));
	//dprintf(2, "after map p: %p old %p\n", game->map, game->old_map);

	//ft_printarr(game->old_map);
	//analyze enm
	//enm_angle = alg_enemy_angle(game);
	//choose direction
	//set priority cells on map
	//find and place piece
}