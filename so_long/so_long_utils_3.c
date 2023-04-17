/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:40:01 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 15:15:55 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_bounds(char **tabtab, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tabtab[0][j])
	{
		if (tabtab[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (tabtab[k][j])
	{
		if (tabtab[k][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (tabtab[i])
	{
		if (tabtab[i++][0] != '1' || tabtab[i][ft_strlen(tabtab[i])])
			return (1);
		i++;
	}
	return (0);
}
/* 
int	ft_path_exist(char **tabtab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tabtab[i])
	{
		j = 0;
		
	}
} */
