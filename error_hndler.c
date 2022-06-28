/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hndler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:46:50 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:47:32 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	chek_carac(t_data *game)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	str = game->map;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'P'
				&& str[i][j] != 'C' && str[i][j] != 'E')
				put_eror("you need to inser oonly '01PCE' in your map\n");
			j++;
		}
		i++;
	}
}

void	chek_rect(t_data *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
			put_eror("you need to inser a rect map");
		i++;
	}
}

void	chek_folder(char *av)
{
	char	**folder;
	int		i;
	char	*str;

	i = 0;
	folder = ft_split(av, '.');
	if (!(ft_2strlen(folder) == 2))
		put_eror("erreur in name of folder");
	if (folder[1][0] != 'b' && folder[1][1] != 'e' && folder[1][2] != 'r')
		put_eror("erreur in name of folder");
}

void	global_err(t_data *game)
{
	chek_rect(game);
	chek_carac(game);
	chek_wall(game->map);
	chek_pce(game->map, game);
}

void	multi_line(char *c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(c) - 1;
	if (c[0] == '\n')
		put_eror("mluti line in your map");
	if (c[j] == '\n')
		put_eror("multi line in your map");
	while (c[i])
	{
		if (c[i] == '\n' && c[i + 1] == '\n')
			put_eror("multi line in your map");
		i++;
	}
}
