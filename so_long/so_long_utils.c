/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:55 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/18 15:05:05 by tpicoule         ###   ########.fr       */
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

int	ft_path_finding(t_map *value)
{
	int		i;
	char	**tabtab2;

	i = 0;
	tabtab2 = malloc(sizeof(value->tabtab));
	if (!tabtab2)
		return (0);
	tabtab2 = value->tabtab;
/* 	printf("tabtab2 =====> %s\n", tabtab2[0]);
	printf("tabtab2 =====> %s\n", tabtab2[1]);
	printf("tabtab2 =====> %s\n", tabtab2[2]);
	printf("tabtab2 =====> %s\n", tabtab2[3]);
	printf("tabtab2 =====> %s\n", tabtab2[4]);
	printf("tabtab2 =====> %s\n", tabtab2[5]);

	printf("\n======================\n\n");

	printf("tabtab =====> %s\n", value->tabtab[0]);
	printf("tabtab =====> %s\n", value->tabtab[1]);
	printf("tabtab =====> %s\n", value->tabtab[2]);
	printf("tabtab =====> %s\n", value->tabtab[3]);
	printf("tabtab =====> %s\n", value->tabtab[4]);
	printf("tabtab =====> %s\n", value->tabtab[5]);
	
	printf("\n======================\n\n"); */

	ft_replace_x(value, tabtab2);
	ft_virus(tabtab2);
/* 	
	printf("tabtab2 =====> %s\n", tabtab2[0]);
	printf("tabtab2 =====> %s\n", tabtab2[1]);
	printf("tabtab2 =====> %s\n", tabtab2[2]);
	printf("tabtab2 =====> %s\n", tabtab2[3]);
	printf("tabtab2 =====> %s\n", tabtab2[4]);
	printf("tabtab2 =====> %s\n", tabtab2[5]);

	printf("\n======================\n\n");

	printf("tabtab =====> %s\n", value->tabtab[0]);
	printf("tabtab =====> %s\n", value->tabtab[1]);
	printf("tabtab =====> %s\n", value->tabtab[2]);
	printf("tabtab =====> %s\n", value->tabtab[3]);
	printf("tabtab =====> %s\n", value->tabtab[4]);
	printf("tabtab =====> %s\n", value->tabtab[5]); */
	if (ft_check_path(tabtab2) != 0)
		return (write(2, "path prob\n", 10));
	return (0);
}
