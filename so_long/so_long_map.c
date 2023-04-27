/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:11:47 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/27 11:00:47 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move_left(t_game *ga)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= ga->map.sizey)
	{
		x = -1;
		while (++x < ga->map.sizex)
		{
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y][x - 1] == 'E')
			{
				if (ft_no_obj_b(ga) == 0)
					ft_exit(ga);
				else
					return ;
			}
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y][x - 1] != '1')
			{
				ga->map.tabtab[y][x] = '0';
				ga->map.tabtab[y][x - 1] = 'P';
				print_key(ga);
				return ;
			}
		}
	}
}

void	move_right(t_game *ga)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= ga->map.sizey)
	{
		x = -1;
		while (++x < ga->map.sizex)
		{
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y][x + 1] == 'E')
			{
				if (ft_no_obj_b(ga) == 0)
					ft_exit(ga);
				else
					return ;
			}
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y][x + 1] != '1')
			{
				ga->map.tabtab[y][x] = '0';
				ga->map.tabtab[y][x + 1] = 'P';
				print_key(ga);
				return ;
			}
		}
	}
}

void	move_top(t_game	*ga)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= ga->map.sizey)
	{
		x = -1;
		while (++x < ga->map.sizex)
		{
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y - 1][x] == 'E')
			{
				if (ft_no_obj_b(ga) == 0)
					ft_exit(ga);
				else
					return ;
			}
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y - 1][x] != '1')
			{
				ga->map.tabtab[y][x] = '0';
				ga->map.tabtab[y - 1][x] = 'P';
				print_key(ga);
				return ;
			}
		}
	}
}

void	move_bot(t_game	*ga)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= ga->map.sizey)
	{
		x = -1;
		while (++x < ga->map.sizex)
		{
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y + 1][x] == 'E')
			{
				if (ft_no_obj_b(ga) == 0)
					ft_exit(ga);
				else
					return ;
			}
			if (ga->map.tabtab[y][x] == 'P' && ga->map.tabtab[y + 1][x] != '1')
			{
				ga->map.tabtab[y][x] = '0';
				ga->map.tabtab[y + 1][x] = 'P';
				print_key(ga);
				return ;
			}
		}
	}
}
