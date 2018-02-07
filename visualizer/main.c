/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:52:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/04 17:52:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int 	main(void)
{
	char	*line;
	int 	i;
	short	end;
	int 	x;
	int		width;
	char	**arr;

	end = 0;
	x = 0;
	system("clear");
	system( "tput civis");
	while (get_next_line(0, &line) > 0)
	{
		i = -1;
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			system("tput cup 3");
			arr = ft_strsplit(line, ' ');
			width = ft_atoi(arr[2]);
			ft_free_2arr(arr);
			continue ;
		}
		if (line[0] == '$')
		{
			x = -1;
			while (ft_isdigit(line[++x]) == 0)
				ft_printf("%c", line[x]);
			if (line[x] == '1')
				ft_printf("1 (\033[34m%C\033[0m)", L'■');
			else
				ft_printf("2 (\033[31m%C\033[0m)", L'■');
			while (line[++x])
				ft_printf("%c", line[x]);
			ft_printf("\n");
			x = 0;
			continue ;
		}
		if (ft_isdigit(line[0]))
		{
			while (line[++i])
			{
				if (line[i] == 'X')
					ft_printf("\033[31m%C\033[0m", L'■');
				else if (line[i] == 'x')
					ft_printf("\033[31m%C\033[0m", /*L'▣'*/ L'☒');
				else if (line[i] == 'O')
					ft_printf("\033[34m%C\033[0m", L'■');
				else if (line[i] == 'o')
					ft_printf("\033[34m%C\033[0m", /*L'▣'*/ L'☒');
				else if (line[i] == '.')
					ft_printf("%C", L'□');
				else
					ft_printf("%c", line[i]);
			}
			ft_printf("%-30c\n", ' ');
		}
		if (line[0] == '=')
		{
			i = 0;
			while (line[i] != 'O' && line[i] != 'X')
				ft_printf("%c", line[i++]);
			if (line[i] == 'X')
				ft_printf("\033[31m%C\033[0m", L'■');
			else if (line[i] == 'O')
				ft_printf("\033[34m%C\033[0m", L'■');
			ft_printf("%-50s\n", &(line[++i]));
			ft_strdel(&line);
			if (end)
			{
				system("tput cnorm");
				exit(0);
			}
			end++;
			continue ;
		}
		ft_strdel(&line);
	}
}