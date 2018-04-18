/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 22:16:38 by ebouvier         ###   ########.fr       */
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
	uint8_t		origin[2];

	while (tetris_l)
	{
		i = 0;
		while (i < 4)
		{
			if (ft_check_place(map->map, tetris_l))
				ft_insert_tetris(map, tetris_l, i);
			++i;
		}
		tetris_l->placed = 1;
		tetris_l = tetris_l->next;
	}
	return (0);
}

uint8_t	ft_insert_tetris(t_map *map, t_tris *tetris, size_t i)
{
	if (ft_check_place(map->map, tetris))
		map->map[tetris->coords[i][0]][tetris->coords[i][1]] = tetris->symbol;
	else
		return (FALSE);
	return (TRUE);
}

uint8_t	ft_check_place(char **map, t_tris *tetris)
{
	size_t 	i;
	uint8_t pieces;

	i = 0;
	pieces = 0;
	while (i < 4)
	{
		if (pieces == 4)
			return (TRUE);
		if (map[tetris->coords[0][0]][tetris->coords[0][1]] == '.')
			++pieces;
		++i;
	}
	return (FALSE);
}