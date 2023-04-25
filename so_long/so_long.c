/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:52:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/25 11:26:50 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include "mlx.h"
//#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_no_obj_b(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tabtab[i])
	{
		j = 0;
		while (game->map.tabtab[i][j])
		{
			if (game->map.tabtab[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.sizey)
	{
		x = 0;
		while (x < game->map.sizex)
		{
			if (game->map.tabtab[y][x] == 'P' && game->map.tabtab[y][x - 1] == 'E')
			{
				if (ft_no_obj_b(game) == 0)
					exit (0);
				else
					return ;
			}
			if (game->map.tabtab[y][x] == 'P'
				&& game->map.tabtab[y][x - 1] != '1')
			{
				game->map.tabtab[y][x] = '0';
				game->map.tabtab[y][x - 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.sizey)
	{
		x = 0;
		while (x < game->map.sizex)
		{
			if (game->map.tabtab[y][x] == 'P' && game->map.tabtab[y][x + 1] == 'E')
			{
				if (ft_no_obj_b(game) == 0)
					exit (0);
				else
					return ;
			}
			if (game->map.tabtab[y][x] == 'P'
				&& game->map.tabtab[y][x + 1] != '1'/*  && game->map.tabtab[y][x + 1] != 'E' */)
			{
				game->map.tabtab[y][x] = '0';
				game->map.tabtab[y][x + 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_top(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.sizey)
	{
		x = 0;
		while (x < game->map.sizex)
		{
			if (game->map.tabtab[y][x] == 'P' && game->map.tabtab[y - 1][x] == 'E')
			{
				if (ft_no_obj_b(game) == 0)
					exit (0);
				else
					return ;
			}
			if (game->map.tabtab[y][x] == 'P'
				&& game->map.tabtab[y - 1][x] != '1'/*  && game->map.tabtab[y - 1][x] != 'E' */)
			{
				game->map.tabtab[y][x] = '0';
				game->map.tabtab[y - 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}


void	move_bot(t_game	*game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.sizey)
	{
		x = 0;
		while (x < game->map.sizex)
		{
			if (game->map.tabtab[y][x] == 'P' && game->map.tabtab[y + 1][x] == 'E')
			{
				if (ft_no_obj_b(game) == 0)
					exit (0);
				else
					return ;
			}
			if (game->map.tabtab[y][x] == 'P'
				&& game->map.tabtab[y + 1][x] != '1'/*  && game->map.tabtab[y + 1][x] != 'E' */)
			{
				game->map.tabtab[y][x] = '0';
				game->map.tabtab[y + 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	print_key(t_game *game)
{
	int	i;

	i = game->i + 1;
	printf("%d\n", i);
	game->i++;
}

int	key_press(int key, t_game *game)
{
	int	i;

	i = 0;
	if (key == 53)
		exit(0);
	if (key == 13)
		move_top(game);
	if (key == 0)
		move_left(game);
	if (key == 1)
		move_bot(game);
	if (key == 2)
		move_right(game);
	if (key == 0 || key == 1 || key == 2 || key == 13)
		print_key(game);
/* 	if (key == 0 || key == 1 || key == 2 || key == 13)
		end_game(game); */
	//printf("%d appuie\n", key);
	return (0);
}

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
	//game->frame++;
	//if (game->frame > 100)
	//	game->frame = 0;
	//printf("frame %d\n", game->frame);
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

	//game.frame = 0;
	i = 0;
	j = 0;
	if (ft_all_checks(argc, argv, &game.map) != 0)
		return (1);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.sizex * 28, (game.map.sizey + 1) * 48, "mlx_1");
	game.img.mur = mlx_xpm_file_to_image(game.mlx, "mur.xpm", &game.a, &game.a);
	game.img.perso = mlx_xpm_file_to_image(game.mlx, "beerus.xpm", &game.a, &game.a);
	game.img.obj = mlx_xpm_file_to_image(game.mlx, "obj.xpm", &game.a, &game.a);
	game.img.ex = mlx_xpm_file_to_image(game.mlx, "ex.xpm", &game.a, &game.a);
	mlx_loop_hook(game.mlx, run, &game);
	mlx_hook(game.win, 2, 0, key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, mlx_loop_end, NULL);
	mlx_loop(game.mlx);
	
/* 	printf("tabtab====> %s\n", value->tabtab[0]);
	printf("tabtab====> %s\n", value->tabtab[1]);
	printf("tabtab====> %s\n", value->tabtab[2]);
	printf("tabtab====> %s\n", value->tabtab[3]);
	printf("tabtab====> %s\n", value->tabtab[4]);
	printf("tabtab====> %s\n", value->tabtab[5]);
	 */
	return (0);
}
