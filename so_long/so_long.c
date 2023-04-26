/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:52:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/26 18:32:20 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_game *game, void *image, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x, y);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.sizey)
	{
		x = 0;
		while (x < game->map.sizex)
		{
			if (game->map.tabtab[y][x] == '1')
				img(game, game->img.mur, y * 48, x * 28);
			else if (game->map.tabtab[y][x] == 'C')
				img(game, game->img.obj, y * 48, x * 28);
			else if (game->map.tabtab[y][x] == 'P')
				img(game, game->img.perso, y * 48, x * 28);
			else if (game->map.tabtab[y][x] == 'E')
				img(game, game->img.ex, y * 48, x * 28);
			x++;
		}
		y++;
	}
}

int	run(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	if (game->map.sizex * 28 > 1200 || (game->map.sizey + 1) * 48 > 640)
		img(game, game->img.f1, 48, 28);
	else
		img(game, game->img.f, 48, 28);
	print_map(game);
	return (0);
}

int	mlx_loop_end(void)
{
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_game	game;

	i = 0;
	j = 0;
	if (ft_all_checks(argc, argv, &game.map) != 0)
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.sizex * 28,
			(game.map.sizey + 1) * 48, "so_long");
	game.img.mur = mlx_xpm_file_to_image(game.mlx, "mur.xpm", &game.a, &game.a);
	game.img.perso = mlx_xpm_file_to_image(game.mlx, "b.xpm", &game.a, &game.a);
	game.img.obj = mlx_xpm_file_to_image(game.mlx, "obj.xpm", &game.a, &game.a);
	game.img.ex = mlx_xpm_file_to_image(game.mlx, "ex.xpm", &game.a, &game.a);
	game.img.f = mlx_xpm_file_to_image(game.mlx, "f.xpm", &game.a, &game.a);
	game.img.f1 = mlx_xpm_file_to_image(game.mlx, "f1.xpm", &game.a, &game.a);
	mlx_loop_hook(game.mlx, run, &game);
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, mlx_loop_end, NULL);
	mlx_loop(game.mlx);
	return (0);
}
