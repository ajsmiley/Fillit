/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:20:03 by achavez           #+#    #+#             */
/*   Updated: 2018/12/11 16:24:03 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_tet_cord(t_node **tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

int		total_tetriminos(char *str)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			total++;
		i++;
	}
	return (total / 4);
}

t_node	*fill_tetri(char *str)
{
	int		total_tetri;
	int		next_tet_set;
	char	tet_symbol;
	t_node	*tmp;
	t_node	*tetri;

	next_tet_set = 0;
	tet_symbol = 'A';
	total_tetri = total_tetriminos(str);
	if (!(tetri = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	tmp = tetri;
	while (total_tetri > 0)
	{
		tmp->tetrimino = tet_symbol;
		set_tet_cord(&tmp, ft_strsub(str, 0 + next_tet_set, 20));
		if (!(tmp->next = (t_node *)malloc(sizeof(t_node))))
			return (NULL);
		tmp = tmp->next;
		total_tetri--;
		tet_symbol++;
		next_tet_set += 21;
	}
	tmp->next = NULL;
	return (tetri);
}

char	*read_file(int fd)
{
	int		read_fd;
	int		i;
	char	*str;
	char	c;

	if (fd < 0)
		return (NULL);
	read_fd = 0;
	i = 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * 572);
	while ((read_fd = read(fd, &c, 1)))
	{
		if (read_fd < 0)
			return (NULL);
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
