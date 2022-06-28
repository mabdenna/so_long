/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heromove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:47:56 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:48:20 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hero_w(t_data *game)
{
	if (game->map[game->px - 1][game->py] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px - 1][game->py] == 'E' && game->i == 1)
		exit(1);
	manag_taharokat(game, 'w');
	return (3);
}

int	hero_s(t_data *game)
{
	if (game->map[game->px + 1][game->py] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px + 1][game->py] == 'E' && game->i == 1)
		exit(1);
	manag_taharokat(game, 's');
	return (3);
}

int	hero_d(t_data *game)
{
	if (game->map[game->px][game->py + 1] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px][game->py + 1] == 'E' && game->i == 1)
		exit(1);
	manag_taharokat(game, 'd');
	return (3);
}

int	hero_a(t_data *game)
{
	if (game->map[game->px][game->py - 1] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px][game->py - 1] == 'E' && game->i == 1)
		exit(1);
	manag_taharokat(game, 'a');
	return (3);
}
