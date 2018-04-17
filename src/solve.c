/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 14:49:03 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Place a tetriminos on map.
**	Iterate over the list and get x and y 
**	Since map->str is linear we need to calculate the index (map_idx)
*/
int			ft_place_tetris(t_map *map, t_tris *tetris_l)
{
	t_tris		*tmp;
	size_t		i;
	uint16_t	size_line;
	uint16_t	map_idx;

	tmp = tetris_l;
	while (tetris_l)
	{
		size_line = ft_size_line(map->str);
		i = 0;
		while (i < 4)
		{
			map_idx = tetris_l->coords[i][0] + (tetris_l->coords[i][1] * (size_line + 1));
			ft_putnbr(map_idx);
			// if (ft_check_tetris(map_idx, size_line, map->str))
			//  	map->str[map_idx] = tetris_l->symbol;
			++i;
		}
		tetris_l->placed = 1;
		tetris_l = tetris_l->next;
	}
	ft_putstr(map->str);
	return (0);
}


// uint8_t		ft_check_tetris(uint16_t map_idx, uint16_t size_line, char **map)
// {
// 	while ()
// 	{
		
// 	}
// }
