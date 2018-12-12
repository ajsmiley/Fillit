/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:41:35 by achavez           #+#    #+#             */
/*   Updated: 2018/12/11 16:35:38 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_connections(char *str, int block)
{
	int connections;
	int i;

	i = 0;
	connections = 0;
	while (i + block < 20 + block)
	{
		if (str[i + block] == '#')
		{
			if ((i + block + 1) < (20 + block) && str[i + block + 1] == '#')
				connections++;
			if ((i + block - 1) >= (0 + block) && str[i + block - 1] == '#')
				connections++;
			if ((i + block + 5) < (20 + block) && str[i + block + 5] == '#')
				connections++;
			if ((i + block - 5) >= (0 + block) && str[i + block - 5] == '#')
				connections++;
		}
		i++;
	}
	if (connections == 6 || connections == 8)
		return (1);
	else
		return (0);
}

int		count_pieces(char *set, int block)
{
	int dot;
	int newline;
	int piece;
	int i;

	dot = 0;
	newline = 0;
	piece = 0;
	i = 0;
	while (i + block < 20 + block && set[i + block] != '\0')
	{
		if (set[i + block] == '.')
			dot++;
		if (set[i + block] == '#')
			piece++;
		if (set[i + block] == '\n')
			newline++;
		i++;
	}
	if (piece == 4 && newline == 4 && dot == 12)
		return (1);
	return (0);
}

int		check_valid_set(char *set)
{
	int i;
	int block;

	i = 0;
	block = 0;
	if (set == NULL || ft_strlen(set) < 19)
		return (0);
	while (set[i + block] != '\0')
	{
		if (!(check_connections(set, block) && count_pieces(set, block)))
			return (0);
		i = 19;
		if (set[i + block] == '\n' && set[i + block + 1] == '\0')
			return (1);
		if (set[i + block] == '\n' && set[i + block + 1] == '\n'
				&& (set[i + block + 2] == '.' || set[i + block + 2] == '#'))
			block += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		spot_is_empty(char **map, t_node *tetri, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetri->y[i] < size && tetri->x[i] < size &&
					map[tetri->y[i]][tetri->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	new_tet_pos(t_node **tetri, int x, int y)
{
	int pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 42;
	pos_y = 42;
	while (i < 4)
	{
		if ((*tetri)->x[i] < pos_x)
			pos_x = (*tetri)->x[i];
		if ((*tetri)->y[i] < pos_y)
			pos_y = (*tetri)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - pos_x + x;
		(*tetri)->y[i] = (*tetri)->y[i] - pos_y + y;
		i--;
	}
}
