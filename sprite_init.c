/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:11:31 by sum               #+#    #+#             */
/*   Updated: 2023/01/25 10:19:21 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_draw(t_game *game, int i, int j, char *buffer, t_image *map)
{
	if (i == 0 && j == 0)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[1]);
	else if(i == 0 && j == game->mapw - 1)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[2]);
	else if(i == game->maph - 1 && j == 0)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[3]);
	else if(i == game->maph - 1 && j == game->mapw - 1)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[4]);
	else if(i == 0 && j != 0)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[5]);
	else if(i != 0 && j == game->mapw - 1)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[6]);
	else if(i == game->maph - 1 && j != 0)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[7]);
	else if(i != 0 && j == 0)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[8]);
	else
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
}

void	sprite_load(t_game *game, int i, int j, char *buffer, t_image *map)
{
	char	parameter;
	
	parameter = game->map[i][j];
	if (parameter == WALL)
		wall_draw(game, i, j, buffer, map);
	else if (parameter == FLOWER)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
	else if (parameter == FLOWER2)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
	else if (parameter == WATER)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
	else if (parameter == WATER_L)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
	else if (parameter == WATER_M)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
	else if (parameter == WATER_R)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);	
	else if (parameter == FLOOR || parameter == PLAYER || parameter == COIN)
		construct_image(buffer, i * 32, j * 32, *map, game->sprites[0]);
}
	
void	sprite_init(t_game *game, char *buffer, t_image *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->maph)
	{
		j = 0;
		while (j < game->mapw)
		{
			sprite_load(game, i, j, buffer, map);
			j++;
		}
		i++;
	}
}

void	create_map(t_game *game)
{
	t_image		map;
	char		*buffer;

	map.image = mlx_new_image(game->mlx, (game->mapw + game->maph)
			* 32, (game->maph + game->mapw) * 32);
	map.w = (game->mapw + game->maph) * 32;
	map.h = (game->maph + game->mapw) * 32;
	buffer = mlx_get_data_addr(map.image, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	sprite_init(game, buffer, &map);
	coin_init(game, buffer, &map);
	exit_init(game, buffer, &map);
	mlx_put_image_to_window(game->mlx, game->win, map.image, 0, 0);
	mlx_destroy_image(game->mlx, map.image);
}