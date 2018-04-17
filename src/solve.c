/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 17:11:21 by ebouvier         ###   ########.fr       */
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

	while (tetris_l)
	{
		i = 0;
		while (i < 4)
		{
			// if (ft_tetris_can_place(map->map, map_idx))
			map->map[tetris_l->coords[i][0]][tetris_l->coords[i][1]] = tetris_l->symbol;
			++i;
		}
		tetris_l->placed = 1;
		tetris_l = tetris_l->next;
	}
	return (0);
}

// /*
// **
// */
// int		ft_move_tetris(t_map *map, t_tris *tetrimino)
// {
	
// }


uint8_t	ft_tetris_can_place(char *map, uint16_t map_idx)
{
	size_t 	i;
	uint8_t pieces;

	i = 0;
	pieces = 0;
	while (map[map_idx + i])
	{
		//ft_putnbr(pieces);
		//ft_putchar('\n');
		if (pieces == 4)
			return (1);
		if(map[map_idx] == '.')
			++pieces;
		++i;
	}
	return (0);
}