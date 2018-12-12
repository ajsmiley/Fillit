/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:58:56 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/11 15:32:02 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 255

typedef struct	s_node
{
	char			tetrimino;
	int				x[4];
	int				y[4];
	struct s_node	*next;
}				t_node;

char			**place_tet(char **map, t_node *tet, int size);
char			**remove_tet(char **map, t_node *tetri, int size);
char			**backtracking(char **map, t_node *tetri, int size);
void			solve(t_node *tetri);
int				check_connections(char *str, int block);
int				count_pieces(char *set, int block);
int				check_valid_set(char *set);
int				spot_is_empty(char **map, t_node *tetri, int size);
void			new_tet_pos(t_node **tetri, int x, int y);
char			**new_map(char **map, int size);
void			print_map(char **map);
char			*read_file(int fd);
t_node			*fill_tetri(char *str);
int				total_tetriminos(char *str);
void			set_tet_cord(t_node **temp, char *str);
#endif
