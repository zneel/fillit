/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/18 19:43:31 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Place a tetriminos on map.
**	Iterate over the list and get x and y
**	Since map->str is linear we need to calculate the index (map_idx)
*/
int		ft_place_tetris(t_map *map, t_tris *tlist)
{
	t_map		*curr_map;
	uint8_t 	i;

	curr_map = map;
	i = 0;
	while (ft_solve(tlist, curr_map) == 0)
	{
		curr_map = ft_resize_map(tlist, i);
		++i;
	}
	return (TRUE);
}

uint8_t ft_solve(t_tris *tlist, t_map *map)
{
	size_t i;

	while (tlist)
	{
		i = 0;
		while (i < 4)
		{
			if (ft_check(map->map, tlist->coords[i][0], tlist->coords[i][1]))
				ft_insert_tetris(&map, tlist, i);
			++i;
		}
		tlist->placed = TRUE;
		tlist = tlist->next;
		ft_putstr("-------MAP-----\n");
		ft_print_map(map->map);
	}
	return (TRUE);
}

uint8_t	ft_insert_tetris(t_map **map, t_tris *ttris, size_t i)
{
	(*map)->map[ttris->coords[i][1]][ttris->coords[i][0]] = ttris->symbol;
	return (TRUE);
}

uint8_t	ft_check(char **map, uint8_t x, uint8_t y)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < ft_map_len(map, x))
		{
			if (map[x][y] != '.')
				return (0);
			++j;

		}
		++i;
	}
	return (1);
}