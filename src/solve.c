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
int		ft_place_tetris(t_map *map, t_tris *tetris_l)
{
	size_t		i;
	uint8_t		x;
	uint8_t		y;
	//uint8_t		origin[2];

	while (tetris_l)
	{
		i = 0;
		while (i < 4)
		{
			x = tetris_l->coords[i][0];
			y = tetris_l->coords[i][1];
			//map->map[tetris_l->coords[i][1]][tetris_l->coords[i][0]] = tetris_l->symbol;
			if (ft_check_place(map->map, x, y) == 1)
				ft_insert_tetris(map, tetris_l, i);
			++i;
		}
		int i = -1;
		while (map->map[++i])
			ft_putstr(map->map[i]);
		ft_putchar('\n');
		tetris_l->placed = 1;
		tetris_l = tetris_l->next;
	}
	return (0);
}

uint8_t	ft_insert_tetris(t_map *map, t_tris *tetris, size_t i)
{
	if (map && tetris)
		map->map[tetris->coords[i][1]][tetris->coords[i][0]] = tetris->symbol;
	return (TRUE);
}

uint8_t	ft_check_place(char **map, uint8_t x, uint8_t y)
{

	if (map[y][x] != '.')
		return (0);
	return (1);
}