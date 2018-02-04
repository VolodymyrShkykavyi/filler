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
	char	command[50];

	end = 0;

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
		/*if (ft_strncmp(line, "Piece", 5) == 0)
		{
			x = 5;
			//ft_printf("piece");
			while (get_next_line(0, &line))
			{

				if (line[0] == '<')
				{
					while (x >= 5)
					{
						ft_bzero(command, 50);
						ft_strcpy(command, "tput cup ");
						ft_strcpy(command, ft_strjoin(command, ft_itoa(x)));
						ft_strcpy(command, ft_strjoin(command, " "));
						ft_strcpy(command, ft_strjoin(command, ft_itoa(width + 7)));
						x--;
						//system("tput cup 3 40");
						system(command);
						ft_printf("%20c\n", ' ');
					}
					break ;
				}
				ft_bzero(command, 50);
				ft_strcpy(command, "tput cup ");
				ft_strcpy(command, ft_strjoin(command, ft_itoa(x)));
				ft_strcpy(command, ft_strjoin(command, " "));
				ft_strcpy(command, ft_strjoin(command, ft_itoa(width + 7)));
				x++;
				//system("tput cup 3 40");
				system(command);
				ft_printf("%s\n", line);
			}
		}*/
		if (line[0] == '$')
		{
			ft_printf("%s\n", line);
			continue ;
		}
		if (ft_isdigit(line[0]))
		{
			while (line[++i])
			{
				if (line[i] == 'X')
					ft_printf("\033[31m%C\033[0m", L'■');
				else if (line[i] == 'x')
					ft_printf("\033[31m%C\033[0m", L'▣');
				else if (line[i] == 'O')
					ft_printf("\033[34m%C\033[0m", L'■');
				else if (line[i] == 'o')
					ft_printf("\033[34m%C\033[0m", L'▣');
				else if (line[i] == '.')
					ft_printf("%C", L'□');
				else
					ft_printf("%c", line[i]);
			}
			ft_printf("\n");
		}
		if (line[0] == '=')
		{
			ft_printf("%s\n", line);
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