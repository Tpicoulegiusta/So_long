/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:53:03 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/19 13:42:31 by tpicoule         ###   ########.fr       */
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

typedef struct s_map
{
	char	**tabtab;
	int		playerx;
	int		playery;
	int		sizey;

}	t_map;

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
int		ft_left_right(t_map *value);
int		ft_reduce_e_p(t_map *value, int i, int j);
int		ft_path_finding(t_map *value);
int		ft_check_path(char **tabtab2);
int		ft_all_checks(int argc, char **argv, t_map *value);
void	ft_virus(char **copy, int x, int y);
int		ft_parse_map(t_map *value, char **copy);
void	ft_virus2(char **copy, int x, int y);

/* char	**ft_virus(char **tabtab2);
void	ft_replace_x(t_map *value, char **tabtab2); */

#endif