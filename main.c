/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:59:00 by sum               #+#    #+#             */
/*   Updated: 2022/12/05 13:59:03 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

long long	check_timestamp(void)
{
	struct timeval	te;
	long long		microtime;

	gettimeofday(&te, NULL);
	microtime = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (microtime);
}

static int	game_loop(t_game *game)
{
	long long	now;
	long long	diff_time;

	now = check_timestamp();
	diff_time = now - game->temp;
	if (diff_time > 15)
	{
		game->temp = now;
		mlx_clear_window(game->mlx, game->win);
		create_map(game);
		player_init(game);

	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game_init(&game, argc);
	map_read(&game, argv[1]);
	map_check(&game);
	map_render(&game);
	mlx_hook(game.win, 2, 1L << 0, keydown_hook, &game);
	mlx_hook(game.win, 17, 0, kill_hook, &game);
	mlx_key_hook(game.win, keyup_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
