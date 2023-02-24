/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:50 by sum               #+#    #+#             */
/*   Updated: 2023/01/20 12:49:51 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_check_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->maph)
	{
		if (ft_strlen(game->map[i]) != game->mapw)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	map_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maph)
	{
		if (i == 0 || i == game->maph - 1)
		{
			j = 0;
			while (j < game->mapw)
			{
				if (game->map[i][j] != WALL)
					return (FALSE);
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != WALL || game->map[i][game->mapw - 1] != WALL)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	map_check_parameter(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->player->direction = LEFT;
	while (i < game->maph)
	{
		j = 0;
		while (j < game->mapw)
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player->x = j * 32 + 7;
				game->player->y = i * 32 + 5;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_count_parameter(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maph)
	{
		j = 0;
		while (j < game->mapw)
		{
			if (game->map[i][j] == COIN)
			{	
				game->c++;
				game->coin->x = j * 32;
				game->coin->y = i * 32;
			}
			else if (game->map[i][j] == EXIT)
				game->e++;
			else if (game->map[i][j] == PLAYER)
				game->p++;
			else if (game->map[i][j] != FLOOR && game->map[i][j] != WALL &&
				game->map[i][j] != WATER && game->map[i][j] != FLOWER &&
				game->map[i][j] != WATER_L && game->map[i][j] != WATER_M &&
				game->map[i][j] != WATER_R && game->map[i][j] != FLOWER2)
				exit_error("Invalid Map. Contents error.");
			j++;
		}
		i++;
	}
	return (0);
}

void	map_check(t_game *game)
{
	if (map_check_rectangular(game) == FALSE)
		exit_error("The map must be rectangular.");
	if (map_check_wall(game) == FALSE)
		exit_error("The map must be surrounded by walls.");
	map_count_parameter(game);
	map_check_parameter(game);
	if (game->c == 0)
		exit_error("Invalid Map. There are no coins.");
	else if (game->e != 1)
		exit_error("Invalid Map. Exit quantity error.");
	else if (game->p != 1)
		exit_error("Invalid Map. Player quantity error.");
}
