/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:48:49 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:49:08 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chek_exit(char **game)
{	
	int	i;
	int	j;

	i = 0;
	while (game[i])
	{
		j = 0;
		while (game[i][j])
		{
			if (game[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	manag_taharokat(t_data *game, char c)
{
	if (c == 'w')
		ft_move_w(game);
	else if (c == 'd')
		ft_move_d(game);
	else if (c == 's')
		ft_move_s(game);
	else if (c == 'a')
		ft_move_a(game);
}

int	taharokat(int keycode, t_data *game)
{	
	game->i = chek_exit(game->map);
	if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == 13 && game->map[game->px - 1][game->py] != '1')
		hero_w(game);
	else if (keycode == 1 && game->map[game->px + 1][game->py] != '1')
		hero_s(game);
	else if (keycode == 2 && game->map[game->px][game->py + 1] != '1')
		hero_d(game);
	else if (keycode == 0 && game->map[game->px][game->py - 1] != '1')
		hero_a(game);
	display_ground(game);
	return (1);
}
