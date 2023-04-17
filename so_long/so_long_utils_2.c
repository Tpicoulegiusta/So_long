/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:23:20 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 17:31:18 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_map *value)
{
	int	i;
	int	j;

	if (value->tabtab == NULL)
		return (write (2, "error tabtab\n", 13));
	i = 0;
	j = ft_strlen(value->tabtab[i]);
	while (value->tabtab[i])
	{
		if (ft_strlen(value->tabtab[i]) != j)
			return (write(2, "error not a rectangle\n", 22));
		i++;
	}
	return (0);
}

int	ft_check_inside(t_map *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (value->tabtab[i])
	{
		j = 0;
		while (value->tabtab[i][j])
		{
			if (value->tabtab[i][j] != '0' && value->tabtab[i][j] != '1'
				&& value->tabtab[i][j] != 'C' && value->tabtab[i][j] != 'E'
					&& value->tabtab[i][j] != 'P')
			{
				printf("tabtab[i][j] ====> %c\n", value->tabtab[i][j]);
				write (1, "caca\n", 5);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_e_p(t_map *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_reduce_e_p(value, i, j) != 0)
		return (1);
	return (0);
}

int	check_c(t_map *value)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (value->tabtab[i])
	{
		j = 0;
		while (value->tabtab[i][j])
		{
			if (value->tabtab[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k < 1)
		return (1);
	return (0);
}

int	ft_check_num_cara(t_map *value)
{
	if (check_e_p(value) != 0)
		return (1);
	if (check_c(value) != 0)
		return (1);
	return (0);
}
