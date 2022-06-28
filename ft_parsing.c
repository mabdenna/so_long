/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:50:56 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:51:00 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	if (*map == '\0')
		put_eror("inser a correct map\n");
	multi_line(map);
	return (map);
}

char	**split_map(char *c)
{
	char	**spl_map;

	spl_map = ft_split(c, '\n');
	return (spl_map);
}

void	chek_wall(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_2strlen(c) - 1;
	while (c[0][i])
	{
		if (c[0][i] != '1' || c[j][i] != '1')
		{
			put_eror("map not surrounded by walls\n");
		}
		i++;
	}
	i = 1;
	j = ft_strlen(c[1]) - 1;
	while (c[i])
	{
		if (c[i][0] != '1' || c[i][j] != '1')
			put_eror("map not surrounded by walls\n");
		i++;
	}
}

void	main_norm(t_data *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->empty, (j * 64), (i * 64));
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, (j * 64), (i * 64));
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->hero, (j * 64), (i * 64));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->colec, (j * 64), (i * 64));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exi, (j * 64), (i * 64));
}

int	exit_mouse(int key)
{
	if (key < 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	return (0);
}
