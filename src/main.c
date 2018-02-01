/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:31:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/30 19:31:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_game(t_game *game)
{
	game->map_h = 0;
	game->map_w = 0;
	game->enm = 0;
	game->plr = 0;
	game->map = NULL;
	game->piece = NULL;
	game->enm_extreme.bot.x = -1;
}
/*
void		init_start_positions(t_game *game)
{
	int		x;
	int 	y;

	x = -1;
	dprintf(2, "init start pos\n");
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == game->plr)
			{
				dprintf(2, "player at %i %i\n", x, y);
				game->plr_start.x = x;
				game->plr_start.y = y;
			}
			else if (game->map[x][y] == game->enm)
			{
				game->enm_start.x = x;
				game->enm_start.y = y;
			}
			if (game->enm_start.x != -1 && game->plr_start.x != -1)
				return ;
		}
	}
}
*/
int 		main(void)
{
	t_game	game;
	char	*line;

	init_game(&game);
	if (get_player(&game))
		return (0);
	while (get_next_line(0, &line))
	{
		if (!(game.map_h))
		{
			if (init_map(&game, &line))
				return (0);
		}
		if (line && ft_isdigit(line[0]))
			read_map(&game, &line);
		if (line && !(ft_strncmp(line, "Piece", 5)))
			read_piece(&game, &line);
		if (line != NULL)
			ft_strdel(&line);
		if (game.piece != NULL)
		{

			//ft_printarr(game.piece);
			algorithm(&game);
			ft_printarr(game.map);
			ft_putstr_fd("\n", 2);
			ft_free_2arr(game.piece);
			game.piece = NULL;
			//ft_putstr_fd("\npiece\n", 2);
			ft_printf("3 3\n");

		}
	}
}
