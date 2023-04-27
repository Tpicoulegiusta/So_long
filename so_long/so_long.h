/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:53:03 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/27 11:01:02 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "mlx.h"
# include "unistd.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_map
{
	char	**tabtab;
	int		playerx;
	int		playery;
	int		sizey;
	int		sizex;
}	t_map;

typedef struct s_image
{
	void	*mur;
	void	*perso;
	void	*obj;
	void	*ex;
	void	*f;
	void	*f1;

}	t_image;

typedef struct s_game
{
	int		frame;
	int		a;
	t_image	img;
	t_map	map;
	void	*mlx;
	void	*win;
	int		i;
}	t_game;

char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int rd);
char	*get_next_line(int fd);
char	*ft_substr2(char *s, int start, int end);
int		ft_check_args(int argc, char **argv);
int		ft_openfile(char **argv);
int		ft_check_map(char **argv, t_map *value);
char	**ft_split(char *s, char c);
char	**ft_countj(char **tabtab, char *s, char c);
int		ft_counti(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *source);
int		ft_check_rectangle(t_map *value);
int		ft_check_inside(t_map *value);
int		ft_check_bounds(t_map *value, int k);
int		ft_check_num_cara(t_map *value);
int		check_e_p(t_map *value);
int		check_c(t_map *value);
int		ft_left_right(t_map *value, int j);
int		ft_reduce_e_p(t_map *value, int i, int j);
int		ft_path_finding(t_map *value);
int		ft_check_path(char **tabtab2);
int		ft_all_checks(int argc, char **argv, t_map *value);
void	ft_virus(char **copy, int x, int y);
int		ft_parse_map(t_map *value, char **copy);
void	ft_virus2(char **copy, int x, int y);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_putnbrexa(unsigned int n);
int		ft_putnbrexaupper(unsigned int n);
int		ft_putnbrexap(unsigned long long n);
int		ft_no_obj_b(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_top(t_game	*game);
void	move_bot(t_game	*game);
void	print_key(t_game *game);
int		key_press(int key, t_game *game);
void	ft_free_copy(char **copy, int length);
void	ft_exit(t_game *game);

#endif