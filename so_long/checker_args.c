/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:06:41 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/19 17:05:07 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_all_checks(int argc, char **argv, t_map *value)
{
	if (ft_check_args(argc, argv) != 0)
		return (write(2, "Wrong args\n", 11));
	if (ft_openfile(argv) != 0)
		return (write(2, "Bad File\n", 9));
	if (ft_check_map(argv, value) != 0)
		return (write(2, "Map Error\n", 10));
	if (ft_path_finding(value) != 0)
		return (write(2, "No path\n", 8));
	return (0);
}