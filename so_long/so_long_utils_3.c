/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:40:01 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/18 14:48:13 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_reduce_e_p(t_map *value, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (value->tabtab[i])
	{
		j = 0;
		while (value->tabtab[i][j])
		{
			if (value->tabtab[i][j] == 'P')
			{
				value->playerx = i;
				value->playery = j;
				k++;
			}
			if (value->tabtab[i][j] == 'E')
				l++;
			j++;
		}
	i++;
	}
	if (k != 1 || l != 1)
		return (1);
	return (0);
}

int	ft_left_right(t_map *value)
{
	int	i;

	i = 0;
	while (value->tabtab[i])
	{
		if (value->tabtab[i++][0] != '1'
			|| value->tabtab[i][ft_strlen(value->tabtab[i])])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_bounds(t_map *value, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value->tabtab[0][j])
	{
		if (value->tabtab[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (value->tabtab[k][j])
	{
		if (value->tabtab[k][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	if (ft_left_right(value) != 0)
		return (1);
	return (0);
}

void	ft_replace_x(t_map *value, char **tabtab2)
{
	int	i;
	int	j;

	i = value->playerx;
	j = value->playery;
	if (tabtab2[i][j] != '1')
		tabtab2[i][j] = 'x';
	if (tabtab2[i - 1][j] != '1')
		tabtab2[i - 1][j] = 'x';
	if (tabtab2[i + 1][j] != '1')
		tabtab2[i + 1][j] = 'x';
	if (tabtab2[i][j - 1] != '1')
		tabtab2[i][j - 1] = 'x';
	if (tabtab2[i][j + 1] != '1')
		tabtab2[i][j + 1] = 'x';
	else
		return ;
}

char	**ft_virus(char **tabtab2)
{
	int	i;
	int	j;

	i = -1;
	while (tabtab2[++i])
	{
		j = -1;
		while (tabtab2[i][++j])
		{
			if (tabtab2[i][j] == 'x')
			{
				if (tabtab2[i - 1][j] != '1')
				tabtab2[i - 1][j] = 'x';
				if (tabtab2[i + 1][j] != '1')
					tabtab2[i + 1][j] = 'x';
				if (tabtab2[i][j - 1] != '1')
					tabtab2[i][j - 1] = 'x';
				if (tabtab2[i][j + 1] != '1')
					tabtab2[i][j + 1] = 'x';
			}
		}
	}
	return (tabtab2);
}
