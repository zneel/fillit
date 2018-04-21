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
	while(ft_solve(map, list) == 0)
		;
	return (map);
}

int8_t	ft_solve(t_map *map, t_tris *list)
{
	t_point *pt;
	size_t map_len;
	t_tris *head;

	pt = (t_point*)malloc(sizeof(t_point));
	pt->x = -1;
	pt->y = 0;
	head = list;
	map_len = ft_map_len(map->map);
	while (list)
	{
		while (ft_check(map, list, pt->x, pt->y) == 0)
		{
			pt->x++;
			if (pt->x > map_len)
			{
				ft_putnbr(pt->x);
				ft_putstr("x over map_len... incrementing y and reseting x\n");
				pt->x = 0;
				pt->y++;
			}
			if (pt->y > map_len && list->symbol == 'A')
			{
				list = head;
				map = ft_resize_map(map);
				pt->x = 0;
				pt->y = 0;
			}
			if (pt->y > map_len)
			{
				list = list->prev;
				pt = ft_remove_ttris(&map, list->symbol - (char)1);
			}
		}
		ft_place(map, list, pt->x, pt->y);
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
	if (x < 0)
		return (FALSE);
	while (i < 4)
	{
		if (x + tris->xy[i][1] < 0
			|| y + tris->xy[i][0] < 0
			|| x + tris->xy[i][1] >= map_len
				|| y + tris->xy[i][0] >= map_len)
			return (FALSE);
		if (map->map[x + tris->xy[i][1]][y + tris->xy[i][0]] != '.')
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
		map->map[x + tris->xy[i][1]][y + tris->xy[i][0]] = tris->symbol;
		++i;
	}
	return (FALSE);
}

t_point *ft_remove_ttris(t_map **map, char c)
{
	uint8_t	i;
	uint8_t j;
	uint8_t found;
	size_t 	map_len;
	t_point *pt;

	i = 0;
	found = 0;
	map_len = ft_map_len((*map)->map);
	pt = (t_point*)malloc(sizeof(t_point));
	while(i < map_len)
	{
		j = 0;
		while (j < map_len)
		{
			if ((*map)->map[i][j] == c)
			{
				if (found == 0)
				{
					found = 1;
					pt->x = j;
					pt->y = i;
				}
				(*map)->map[i][j] = '.';
			}
			++j;
		}
		++i;
	}
	return (pt);
}