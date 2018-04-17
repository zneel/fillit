/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 20:03:50 by ebouvier         ###   ########.fr       */
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
	uint8_t		x;
	uint8_t		y;
	
	while (tetris_l)
	{
		i = 0;
		origin[0] = tetris_l->coords[i][0];
		origin[1] = tetris_l->coords[i][1];
		while (i < 4)
		{
			x = tetris_l->coords[i][0] - origin[0];
			y = tetris_l->coords[i][1] - origin[1];
			if(ft_tetris_can_place(map->map, x, y))
			{
				if (i == 0)
					map->map[0][0] = tetris_l->symbol;
				map->map[y][x] = tetris_l->symbol;
			}			
			i++;
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
	
	
	uint8_t	ft_tetris_can_place(char **map, uint8_t x, uint8_t y)
	{
		size_t 	i;
		size_t	j;
		uint8_t pieces;
		i = 0;
		j = 0;
		pieces = 0;
		while (map[x])
		{
			
			if (map[x][y])
			{
				ft_putnbr(pieces);
				ft_putchar('\n');
				if (pieces == 4)
					return (1);
				if(map[x][y] == '.')
					++pieces;
			}
		}
		return (0);
	}