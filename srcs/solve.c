/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:21:39 by achavez           #+#    #+#             */
/*   Updated: 2018/12/11 15:29:34 by achavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**place_tet(char **map, t_node *tetri, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetri->y[i] == y && tetri->x[i] == x)
			{
				map[y][x] = tetri->tetrimino;
				i++;
			}
			x++;
		}
		y++;
	}
	return (map);
}

char	**remove_tet(char **map, t_node *tetri, int size)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetri->tetrimino)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

char	**backtracking(char **tet_map, t_node *tetri, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetri->next == NULL)
		return (tet_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			new_tet_pos(&tetri, x, y);
			if (spot_is_empty(tet_map, tetri, size))
				map = backtracking(place_tet(tet_map, tetri, size),
						tetri->next, size);
			if (map)
				return (map);
			tet_map = remove_tet(tet_map, tetri, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	solve(t_node *tetri)
{
	char	**result;
	char	**map;
	int		size;

	size = 2;
	map = NULL;
	result = NULL;
	map = new_map(map, size);
	while (!(result = backtracking(map, tetri, size)))
	{
		size++;
		ft_memdel((void**)map);
		map = new_map(map, size);
	}
	print_map(result);
}
