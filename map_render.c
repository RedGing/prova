/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:57:13 by sum               #+#    #+#             */
/*   Updated: 2023/01/20 13:57:14 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*save_sprites(int num, char *path, t_game *game)
{
	int	i;
	char	*p;
	t_image	*sprites;

	i = 0;
	printf("hello\n");
	sprites = ft_malloc(sizeof(t_image) * num, &game->alloc);
	printf("hello 2\n");
	if (!sprites)
		return (NULL);
	while (i < num)
	{
		p = ft_strjoin(path, ft_itoa(i));
		p = ft_strjoin(p, ".xpm");
		sprites[i] = generate_image(*game, p, &game->img_alloc);
		if (!sprites[i].image)
			return (NULL);
		i++;
		free(p);
	}
	return (sprites);
}

void	init_save_sprites(t_game *game)
{
	game->sprites = save_sprites(9, WALL_XPM, game);
	game->sprites = save_sprites(8, EXIT_XPM, game);
	game->sprites = save_sprites(1, FLOOR_XPM, game);
	game->sprites = save_sprites(1, FLOWER_XPM, game);
	game->sprites = save_sprites(1, FLOWER2_XPM, game);
	game->sprites = save_sprites(1, WATER_XPM, game);
	game->sprites = save_sprites(1, WATER_L_XPM, game);
	game->sprites = save_sprites(1, WATER_M_XPM, game);
	game->sprites = save_sprites(1, WATER_R_XPM, game);
	game->sprites = save_sprites(4, COIN_XPM, game);
	game->sprites = save_sprites(34, PLAYER_XPM, game);
}

void	init_mlx(t_game *game)
{
	if (game->mlx == NULL)
		exit_error("Error in mlx. Try again.");
	game->win = mlx_new_window(game->mlx, game->mapw * 32, game->maph * 32, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		exit_error("Failed to create the window.");
	}
}

void	map_render(t_game *game)
{
	init_mlx(game);
	init_save_sprites(game);
}	
