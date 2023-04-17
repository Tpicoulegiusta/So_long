/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:55 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 18:43:53 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (write(2, "Not enough args\n", 16));
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
		return (write(2, "Fd prob\n", 8));
	//CLOSE POSSIBLE SI JAMAIS YA SOUCIS
	return (0);
}

int	ft_check_map(char **argv, t_map *value)
{
	int		map;
	char	*tab;
	char	*tab2;
	int		k;

	k = -1;
	map = open(argv[1], O_RDONLY, 0777);
	tab = get_next_line(map);
	while (tab != '\0')
	{
		value->tabtab = ft_split(tab, '\n');
		tab2 = get_next_line(map);
		tab = ft_strjoin(tab, tab2);
		k++;
	}
	if (ft_check_rectangle(value) != 0)
		return (1);
	if (ft_check_inside(value) != 0)
		return (1);
	if (ft_check_bounds(value, k) != 0)
		return (1);
	if (ft_check_num_cara(value) != 0)
		return (1);
	return (0);
}

void	ft_replace_x(t_map *value)
{
	int	i;
	int	j;

	i = value->playerx;
	j = value->playery;
	while (value->tabtab[i])
	{
		//j = 0;
		while (value->tabtab[i][j])
			if (value->tabtab[i][j] == '1')
				return ;
			else
			{
				value->tabtab[i][j] = 'x';
				j++;
			}
		i++;
	}
}

int	ft_path_finding(t_map *value)
{
	int	i;

	i = 0;
	ft_replace_x(value);
	

	printf("tabtab =====> %s\n", value->tabtab[0]);
	printf("tabtab =====> %s\n", value->tabtab[1]);
	printf("tabtab =====> %s\n", value->tabtab[2]);
	printf("tabtab =====> %s\n", value->tabtab[3]);
	printf("tabtab =====> %s\n", value->tabtab[4]);
	printf("tabtab =====> %s\n", value->tabtab[5]);
	return (0);
}
