/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:27:30 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/26 17:38:32 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path(char **tabtab2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (tabtab2[i])
	{
		j = 0;
		while (tabtab2[i][j])
		{
			if (tabtab2[i][j] == 'E' || tabtab2[i][j] == 'C')
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

void	ft_virus(char **copy, int x, int y)
{
	if (copy[y][x] != 'C' && copy[y][x] != '0' && copy[y][x] != 'P')
		return ;
	copy[y][x] = 'X';
	ft_virus(copy, x + 1, y);
	ft_virus(copy, x - 1, y);
	ft_virus(copy, x, y - 1);
	ft_virus(copy, x, y + 1);
}

void	ft_virus2(char **copy, int x, int y)
{
	if (copy[y][x] != 'E' && copy[y][x] != '0' && copy[y][x] != 'X')
		return ;
	copy[y][x] = 'S';
	ft_virus2(copy, x + 1, y);
	ft_virus2(copy, x - 1, y);
	ft_virus2(copy, x, y - 1);
	ft_virus2(copy, x, y + 1);
}

int	ft_parse_map(t_map *value, char **copy)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	ft_virus(copy, value->playerx, value->playery);
	ft_virus2(copy, value->playerx, value->playery);
	i = 0;
	while (i <= value->sizey)
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_path_finding(t_map *value)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (value->sizey + 1));
	while (i <= value->sizey)
	{
		copy[i] = ft_strdup(value->tabtab[i]);
		i++;
	}
	if (ft_parse_map(value, copy) != 0)
		return (ft_free_copy(copy, value->sizey), 1);
	return (ft_free_copy(copy, value->sizey), 0);
}
