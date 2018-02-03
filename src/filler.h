/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/01/30 19:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define ABS (x) ((x > 0) ? (x) : (-x))

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int 			y;
}					t_point;

typedef struct		s_game
{
	char			**map;
	char			**piece;
	char			enm;
	char			plr;
	t_point			enm_start;
	t_point			plr_start;
	short			map_h;
	short			map_w;
	short			piece_h;
	short			piece_w;
}					t_game;

typedef struct		s_alg
{
	char			reached;
	t_point			result;
}					t_alg;

int					get_player(t_game *game);
int 				init_map(t_game *game, char **line);
void				read_map(t_game *game, char **line);
void				read_piece(t_game *game, char **line);
void				init_start_positions(t_game *game);
void				algorithm(t_game *game);



#endif
