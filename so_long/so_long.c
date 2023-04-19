/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:52:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/19 15:56:36 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include "mlx.h"
//#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	ft_putchar('X');
	return (0);
}

/* int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_1");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
} */


int	main(int argc, char **argv)
{
	t_map	*value;
	void	*mlx_ptr;
	void	*win_ptr;

	value = malloc(sizeof(t_map));
	if (ft_all_checks(argc, argv, value) != 0)
		return (1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_1");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
/* 	printf("tabtab====> %s\n", value->tabtab[0]);
	printf("tabtab====> %s\n", value->tabtab[1]);
	printf("tabtab====> %s\n", value->tabtab[2]);
	printf("tabtab====> %s\n", value->tabtab[3]);
	printf("tabtab====> %s\n", value->tabtab[4]);
	printf("tabtab====> %s\n", value->tabtab[5]);
	 */
	return (0);
}
