/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:52:15 by mabdenna          #+#    #+#             */
/*   Updated: 2022/06/27 22:52:16 by mabdenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_line(char **stock)
{
	char	*tmp;
	char	*ligne;
	int		i;

	i = 0;
	if (!*stock || !*stock[0])
	{
		free(*stock);
		return (NULL);
	}
	while ((*stock)[i] != '\n' && (*stock)[i])
		i++;
	if ((*stock)[i] == '\n')
	{
		ligne = ft_substr(*stock, 0, i + 1);
		tmp = ft_strdup(*stock + i + 1);
		free(*stock);
		*stock = tmp;
		return (ligne);
	}
	ligne = ft_strdup(*stock);
	free(*stock);
	*stock = NULL;
	return (ligne);
}

void	ft_readtext(int fd, ssize_t nb, char *text, char **stock)
{
	char	*tmp;

	while (nb > 0)
	{
		if (!*stock)
			*stock = ft_strdup("");
		tmp = ft_strjoin(*stock, text);
		free(*stock);
		*stock = tmp;
		if (ft_strchr(text, '\n'))
			break ;
		nb = read(fd, text, BUFFER_SIZE);
		text[nb] = '\0';
	}
	free(text);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*text;
	static char	*stock;
	ssize_t		nb;

	text = malloc(BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	nb = read(fd, text, BUFFER_SIZE);
	if (nb == -1)
	{
		free(text);
		return (NULL);
	}
	text[nb] = '\0';
	ft_readtext(fd, nb, text, &stock);
	line = ft_line(&stock);
	return (line);
}
