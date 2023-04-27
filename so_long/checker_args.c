/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:06:41 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/27 11:38:29 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_all_checks(int argc, char **argv, t_map *value)
{
	if (ft_check_args(argc, argv) != 0)
		return (write(2, "Error\nWrong args\n", 17));
	if (ft_openfile(argv) != 0)
		return (write(2, "Error\nBad File\n", 15));
	if (ft_check_map(argv, value) != 0)
		return (write(2, "Error\nMap Error\n", 16));
	if (ft_path_finding(value) != 0)
		return (write(2, "Error\nNo path\n", 14));
	return (0);
}
