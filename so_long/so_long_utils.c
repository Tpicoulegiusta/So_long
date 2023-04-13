/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:47:55 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/13 12:30:44 by tpicoule         ###   ########.fr       */
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

int	ft_check_map(char **argv)
{
	int		map;
	char	*tab;
	char	*tab2;
	char	**tabtab;

	map = open(argv[1], O_RDONLY, 0777);
	tab = get_next_line(map);
	while (tab != '\0')
	{
		tabtab = ft_split(tab, '\n');
		tab2 = get_next_line(map);
		tab = ft_strjoin(tab, tab2);
		//printf ("tab ====> %s", tab);
	}
	if (ft_check_rectangle(tabtab) != 0)
		return (1);
	printf ("\ntabtab ====> %s\n", tabtab[0]);
	printf ("tabtab ====> %s\n", tabtab[1]);
	printf ("tabtab ====> %s\n", tabtab[2]);
	printf ("tabtab ====> %s\n", tabtab[3]);
	printf ("tabtab ====> %s\n", tabtab[4]);
	printf ("tabtab ====> %s\n", tabtab[5]);
	return (0);
}
