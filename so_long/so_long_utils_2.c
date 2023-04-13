/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:23:20 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/13 13:59:38 by tpicoule         ###   ########.fr       */
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
			return (write(2, "erore not a rectangle\n", 22));
		i++;
	}
	return (0);
}
