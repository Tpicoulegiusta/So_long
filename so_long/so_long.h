/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:53:03 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/17 15:22:56 by tpicoule         ###   ########.fr       */
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
}	t_map;

char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int rd);
char	*get_next_line(int fd);
char	*ft_substr2(char *s, int start, int end);
int		ft_check_args(int argc, char **argv);
int		ft_openfile(char **argv);
int		ft_check_map(char **argv);
char	**ft_split(char *s, char c);
char	**ft_countj(char **tabtab, char *s, char c);
int		ft_counti(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *source);
int		ft_check_rectangle(char **tabtab);
int		ft_check_inside(char **tabtab);
int		ft_check_bounds(char **tabtab, int k);
int		ft_check_num_cara(char **tabtab);
int		check_e_p(char **tabtab);
int		check_c(char **tabtab);
int		ft_path_exist(char **tabtab);

#endif