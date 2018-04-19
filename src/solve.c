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
** 1_ need to check if i can place the tetrimino on the map
** 2_ if yes -> place it and go next tetrimino
** 3_ if no -> increment its coords until map len in x and y
** 4_ if it fits -> place it with new coords and go next tetrimino
** 5_ if not increase map size and go back to 1_
*/

t_map	*ft_resolve(t_map *map, t_tris *list)
{
	t_map *tmp_map;

	tmp_map = map;
	while(ft_solve(tmp_map, list) == 0)
		tmp_map = ft_resize_map(list);
	return (tmp_map);
}

int8_t	ft_solve(t_map *map, t_tris *list)
{
	int8_t x;
	int8_t y;
	size_t map_len;

	x = 0;
	y = 0;
	map_len = ft_map_len(map->map);
	while (list)
	{
		if (ft_check(map, list, x, y))
		{
			if (x > map_len)
			{
				x = 0;
				y++;
			}
			if (y > map_len && list->symbol == 'A')
			{
				/*free(map);
				map = ft_resize_map(list); // need head list !*/
				x = 0;
				y = 0;
			}
			if (y > map_len)
			{

			}
			x++;
		}
		ft_place(map, list, x, y);
		list = list->next;
	}
	return (TRUE);
}


int8_t	ft_check(t_map *map, t_tris *tris, int8_t x, int8_t y)
{
	size_t i;
	size_t map_len;

	i = 0;
	map_len = ft_map_len(map->map);
	if (x < 0 && y < 0 && x > map_len && y > map_len)
		return (FALSE);
	if (map->map[x + tris->coords[i][1]][y + tris->coords[i][0]] != '.')
		return (FALSE);
	++i;
	while (i < 3)
	{
		if (x + tris->coords[i][1] - tris->coords[0][1] < 0 && x +
																	   tris->coords[i][0] - tris->coords[0][0] < 0)
			return (FALSE);
		if (x + tris->coords[i][1] - tris->coords[0][1] > map_len && x +
															   tris->coords[i][0] - tris->coords[0][0] > map_len)
			return (FALSE);
		if (map->map[x + tris->coords[i][1] - tris->coords[0][0] ][y +
				tris->coords[i][0] - tris->coords[0][1]] !=
				'.')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int8_t ft_place(t_map *map, t_tris *tris, int8_t x, int8_t y)
{
	size_t i;

	i = 0;
	while (i < 4)
	{
		map->map[tris->coords[i][1]][tris->coords[i][0]] =
				tris->symbol;
		++i;
	}
	return (FALSE);
}

uint8_t ft_remove_ttris(t_map *map, char c)
{
	size_t i;
	size_t j;
	size_t map_len;

	i = 0;
	map_len = ft_map_len(map->map);
	while(i < map_len)
	{
		j = 0;
		while (j < map_len)
		{
			if (map->map[i][j] == c)
				map->map[i][j] = '.';
			++j;
		}
		++i;
	}
}