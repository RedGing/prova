/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:11 by femorell          #+#    #+#             */
/*   Updated: 2023/02/23 15:28:17 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	construct_image(char *buffer, int i, int j, t_image image2, t_image image)
{
	int	y;
	int	x;
	int	pixel;
	int	og;

	y = 0;
	while (y <= image.h)
	{
		x = 0;
		while (x <= image.w)
		{
			pixel = ((i + y) * image2.line_length) + ((j + x) * 4);
			og = (y * image.line_length) + (x * 4);
			if (!(image.addr[og] == 0 && image.addr[og + 1] == 0
					&& image.addr[og + 2] == 0))
			{
				buffer[pixel + 0] = image.addr[og + 0];
				buffer[pixel + 1] = image.addr[og + 1];
				buffer[pixel + 2] = image.addr[og + 2];
				buffer[pixel + 3] = image.addr[og + 3];
			}
			x++;
		}
		y++;
	}
}

t_image	generate_image(t_game game, char *path, t_alloc **alloc)
{
	t_image	sprite;

	sprite.image = mlx_xpm_file_to_image(game.mlx, path, &sprite.w, &sprite.h);
	if (!sprite.image)
		return (sprite);
	sprite.addr = mlx_get_data_addr(sprite.image, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	malloc_add(alloc, malloc_new(sprite.image));
	return (sprite);
}
