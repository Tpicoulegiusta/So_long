/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:52:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 15:18:51 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include "mlx.h"
//#include "unistd.h"

/* void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_1");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
 */

int	main(int argc, char **argv)
{
	if (ft_check_args(argc, argv) != 0)
		return (write(2, "Wrong args\n", 11));
	if (ft_openfile(argv) != 0)
		return (write(2, "Bad File\n", 9));
	if (ft_check_map(argv) != 0)
		return (write(2, "Map Error\n", 10));
		
	return (0);
}
