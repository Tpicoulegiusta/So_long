/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:09 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/27 11:00:52 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	print_key(t_game *game)
{
	int	i;

	i = game->i + 1;
	ft_printf("%d\n", i);
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
	return (0);
}
