/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:22:51 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/11 16:22:57 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*tets;
	t_node	*tetri;

	fd = 0;
	tets = NULL;
	if (ac != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	tets = read_file(fd);
	if (!check_valid_set(tets))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	tetri = fill_tetri(tets);
	solve(tetri);
	free(tetri);
	free(tets);
	return (0);
}
