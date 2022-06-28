/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:22 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:50:46 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_w(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px - 1][game->py] = 'P';
	game->px--;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	ft_move_d(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px][game->py + 1] = 'P';
	game->py++;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	ft_move_s(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px + 1][game->py] = 'P';
	game->px++;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	ft_move_a(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px][game->py - 1] = 'P';
	game->py--;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}
