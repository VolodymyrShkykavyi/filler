/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:56:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/30 19:56:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** format of first string: "$$$ exec p1 : [vshkykav.filler]"
*/

int		get_player(t_game *game)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (1);
	if (line[10] == '1')
	{
		game->plr = 'O';
		game->enm = 'X';
	}
	else if (line[10] == '2')
	{
		game->plr = 'X';
		game->enm = 'O';
	}
	else
		return (1);
	return (0);
}
