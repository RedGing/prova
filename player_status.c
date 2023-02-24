/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:10 by sum               #+#    #+#             */
/*   Updated: 2023/02/14 15:04:12 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_status(t_game *game)
{
	char	*movements;
	void	*bn;
	int	bn_height;
	int	bn_width;
	
	bn = mlx_xpm_file_to_image(game->mlx, BANNER_XPM, &bn_width, &bn_height);
	mlx_put_image_to_window(game->mlx, game->win, bn, 0, 10);
	movements = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 5, 23, 0xC41E3A, "move");
	mlx_string_put(game->mlx, game->win, 32, 23, 0xC41E3A, movements);
	free(movements);
}
