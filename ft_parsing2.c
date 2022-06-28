/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:51:21 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:51:35 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chek_p(char **str, t_data *game)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				game->px = i;
				game->py = j;
				p++;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		put_eror("you can have only one player\n");
}

int	chek_c(char **str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		put_eror("you need to have at least one colec in your map \n");
	return (c);
}

void	chek_e(char **str)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 0)
		put_eror("you need to have at least one exit in your map \n");
}

int	chek_pce(char **str, t_data *game)
{
	int	i;

	chek_p(str, game);
	chek_e(str);
	i = chek_c(str);
	return (i);
}
