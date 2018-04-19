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
	uint8_t 	i;

	while (ft_solve(tlist, map) == 0)
		;
	return (TRUE);
}

uint8_t ft_solve(t_tris *tlist, t_map *map)
{
	size_t i;

	while (tlist)
	{
		i = 0;
		if (ft_check(map->map, tlist->coords) == 0)
			map = ft_resize_map(tlist);
		while (i < 4)
			ft_insert_tetris(&map, tlist, i++);
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

uint8_t	ft_check(char **map, uint8_t tab[4][2])
{
	size_t i;
	size_t j;
	uint8_t map_len;

	i = 0;
	map_len = ft_map_len(map, (uint8_t)i);
	while (i < map_len)
	{
		j = 0;
		while (j < map_len)
		{
			if (map[tab[i][0]][tab[i][1]] != '.')
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}