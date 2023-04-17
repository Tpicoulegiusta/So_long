/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:23:20 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 13:41:40 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(char **tabtab)
{
	int	i;
	int	j;

	if (tabtab == NULL)
		return (write (2, "error tabtab\n", 13));
	i = 0;
	j = ft_strlen(tabtab[i]);
	while (tabtab[i])
	{
		if (ft_strlen(tabtab[i]) != j)
			return (write(2, "error not a rectangle\n", 22));
		i++;
	}
	return (0);
}

int	ft_check_inside(char **tabtab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tabtab[i])
	{
		j = 0;
		while (tabtab[i][j])
		{
			if (tabtab[i][j] != '0' && tabtab[i][j] != '1'
				&& tabtab[i][j] != 'C' && tabtab[i][j] != 'E'
					&& tabtab[i][j] != 'P')
			{
				printf("tabtab[i][j] ====> %c\n", tabtab[i][j]);
				write (1, "caca\n", 5);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_e_p(char **tabtab)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (tabtab[i])
	{
		j = 0;
		while (tabtab[i][j])
		{
			if (tabtab[i][j] == 'P')
				k++;
			if (tabtab[i][j] == 'E')
				l++;
			j++;
		}
	i++;
	}
	if (k > 1 || l > 1)
		return (1);
	return (0);
}

int	check_c(char **tabtab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (tabtab[i])
	{
		j = 0;
		while (tabtab[i][j])
		{
			if (tabtab[i][j] == 'C')
				k++;
			j++;
		}
		i++;
	}
	if (k < 1)
		return (1);
	return (0);
}

int	ft_check_num_cara(char **tabtab)
{
	if (check_e_p(tabtab) != 0)
		return (1);
	if (check_c(tabtab) != 0)
		return (1);
	return (0);
}
