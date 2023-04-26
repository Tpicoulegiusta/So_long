/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:55 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/26 17:28:59 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (1);
	i = ft_strlen(argv[1]) - 4;
	while (i < ft_strlen(argv[1]))
	{
		if (argv[1][i++] != '.')
			return (1);
		if (argv[1][i++] != 'b')
			return (1);
		if (argv[1][i++] != 'e')
			return (1);
		if (argv[1][i++] != 'r')
			return (1);
		if (argv[1][i] != '\0')
			return (1);
	}
	return (0);
}

int	ft_openfile(char **argv)
{
	int	map;
	int	directory;

	directory = open(argv[1], O_DIRECTORY, 0777);
	map = open(argv[1], O_RDONLY, 0777);
	if (directory != -1 || map == -1)
		return (1);
	return (0);
}

int	ft_reduce_check(t_map *value, int k)
{
	if (k < 2)
		return (1);
	if (ft_check_rectangle(value) != 0)
		return (1);
	if (ft_check_inside(value) != 0)
		return (1);
	if (ft_check_bounds(value, value->sizey) != 0)
		return (1);
	if (ft_check_num_cara(value) != 0)
		return (1);
	return (0);
}

char	*ft_strjoinfree2(char *stock, char *tmp)
{
	char	*str;

	str = ft_strjoin(stock, tmp);
	if (stock)
		free (stock);
	return (str);
}

int	ft_check_map(char **argv, t_map *value)
{
	int		map;
	char	*tab;
	char	*tab2;

	value->sizey = -1;
	map = open(argv[1], O_RDONLY, 0777);
	tab = get_next_line(map);
	while (tab != '\0')
	{
		value->sizey++;
		tab2 = get_next_line(map);
		if (!tab2)
			break ;
		if (tab2[0] == '\n')
			return (1);
		tab = ft_strjoinfree2(tab, tab2);
		free(tab2);
	}
	value->tabtab = ft_split(tab, '\n');
	free(tab);
	if (ft_reduce_check(value, value->sizey) != 0)
		return (1);
	return (0);
}
