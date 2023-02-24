/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:21:26 by sum               #+#    #+#             */
/*   Updated: 2023/01/19 14:21:29 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_size(t_game *game, int fd)
{
	char	c;
	int		temp_w;

	temp_w = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			game->maph++;
			temp_w = 0;
		}
		else
			temp_w++;
		if (temp_w > game->mapw)
			game->mapw = temp_w;	
	}
	close (fd);
}

static void	map_malloc(t_game *game, int fd)
{
	int	i;

	map_size(game, fd);
	if (game->maph == 0 || game->mapw == 0)
		exit_error("Invalid map. It's empty.");
	game->map = (char **)malloc(sizeof(char *) * game->maph);
	i = 0;
	while (i < game->maph)
	{
		game->map[i] = (char *)malloc(sizeof(char) * game->mapw + 1);
		i++;
	}
}

char	*strjoin_free(char *s1, char *s2)
{
	char	*new;
	
	new = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (new);
}

int	map_init(t_game *game, char *filename)
{
	char	*mapping;
	char	*temp;
	int	fd;
	
	fd = open(filename, O_RDONLY);
	mapping = ft_strdup("");
	while (1)
	{
		temp = get_next_line(fd);
		if(temp == NULL)
			break;
		mapping = strjoin_free(mapping, temp);
	}
	game->map = ft_split(mapping, '\n');
	free(mapping);
	close(fd);
	return (fd);
}

void	map_read(t_game *game, char *filename)
{
	int	fd;
	int	len;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit_error("Failed to open the map");
	len = ft_strlen(filename);
	if (len < 4 || !ft_strnstr(&filename[len - 4], ".ber", 4))
		exit_error("Map file extention is not .ber");
	map_malloc(game, fd);
	map_init(game, filename);
}
