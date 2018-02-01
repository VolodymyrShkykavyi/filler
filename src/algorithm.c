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
#include <stdio.h>

/*static t_point	alg_find_enemy(t_game *game)
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

t_point	alg_enemy_possible_pos(t_game *game)
{
	t_point		enm_pos;
	t_point		result;
	int 		tmp;

	enm_pos = alg_find_enemy(game);
	//dprintf(2, "\npos: %i %i\n", enm_pos.x, enm_pos.y);
	tmp = (game->enm_start.x - enm_pos.x > 0) ? 2 : -2;
	result.x = enm_pos.x + tmp;
	tmp = (game->enm_start.y - enm_pos.y > 0) ? 2 : -2;
	result.y = enm_pos.y + tmp;
	return (result);
}*/

static void	check_priority_place(t_game *game, t_point pos, short radius, char prior)
{
	if (pos.x - radius >= 0 && pos.x + radius <= game->map_h)
	{
		if (game->map[pos.x + radius][pos.y] == '.')
			game->map[pos.x + radius][pos.y] = prior;
		if (game->map[pos.x - radius][pos.y] == '.')
			game->map[pos.x - radius][pos.y] = prior;
	}
	if (pos.y - radius >= 0 && pos.y + radius <= game->map_w)
	{
		if (game->map[pos.x][pos.y + radius] == '.')
			game->map[pos.x][pos.y + radius] = prior;
		if (game->map[pos.x][pos.y - radius] == '.')
			game->map[pos.x][pos.y - radius] = prior;
	}
}

void		alg_set_priority(t_game *game)
{
	t_point	pos;
	pos.x = -1;
	while (game->map[++pos.x])
	{
		pos.y = -1;
		while (game->map[pos.x][++pos.y])
		{
			if (game->map[pos.x][pos.y] == game->enm)
			{
				check_priority_place(game, pos, 1, '5');
				check_priority_place(game, pos, 2, '6');
			}
			else if (pos.x == 0 || pos.x == game->map_h - 1 ||
					pos.y == 0 || pos.y == game->map_w - 1)
				if (game->map[pos.x][pos.y] != game->enm &&
						game->map[pos.x][pos.y] != game->plr)
					game->map[pos.x][pos.y] = '9';
		}
	}
}

t_enemy	alg_get_enemy_extremepos(t_game *game)
{
	t_enemy	enemy;
	t_point	pos;

	pos.x = -1;
	enemy.bot.x = -1;
	enemy.top.x = game->map_h;
	enemy.left.y = game->map_w;
	enemy.right.y = -1;
	while (game->map[++pos.x])
	{
		pos.y = -1;
		while (game->map[pos.x][++pos.y])
			if (game->map[pos.x][pos.y] == game->enm)
			{
				if (pos.x < enemy.top.x)
					enemy.top = pos;
				if (pos.x > enemy.bot.x)
					enemy.bot = pos;
				if (pos.y > enemy.right.y)
					enemy.right = pos;
				if (pos.y < enemy.left.y)
					enemy.left = pos;
			}
	}
	return (enemy);
}

short	alg_get_close_direction(t_game *game)
{
	short	dir;
	t_enemy	enemy;

	enemy = alg_get_enemy_extremepos(game);
	return (dir = 0);
}

void	algorithm(t_game *game)
{
	//t_point	enm_possible;
	//short	close_dir;
	//analyze enm
	//ft_printarr(game->map);
	alg_set_priority(game);
	//close_dir = alg_get_close_direction(game);
	//dprintf(2, "\npos %c: %i %i\n",game->enm ,game->enm_start.x, game->enm_start.y);
	//ft_putstr_fd("\ntest \n", 2);
	//ft_putstr_fd(game->piece[0], 2);
	//choose direction
	//set priority cells on map
	//find and place piece

}