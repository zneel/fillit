/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/05/07 15:07:20 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_solve(t_tris *current, int map_len)
{
	register char **map;

	map = NULL;
	map = ft_map(map, map_len);
	while (ft_place_piece(map, map_len, current) == 0)
	{
		map_len++;
		map = ft_resize_map(map, map_len);
	}
	return (map);
}

int		ft_check(t_tris *current, char **map, int map_len, t_point *xy)
{
	register size_t i;

	i = 0;
	if (xy->x < 0)
		return (FALSE);
	while (i < 4)
	{
		if (xy->x + current->xy[i][1] < 0
				|| xy->y + current->xy[i][0] < 0
				|| xy->x + current->xy[i][1] >= map_len
				|| xy->y + current->xy[i][0] >= map_len)
			return (FALSE);
		if (map[xy->y + current->xy[i][0]][xy->x + current->xy[i][1]] !=
				CHAR_EMPTY)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

char	**ft_insert_piece(t_tris *current, char **map, t_point *xy)
{
	register int i;

	i = 0;
	while (i < 4)
	{
		map[xy->y + current->xy[i][0]][xy->x + current->xy[i][1]] =
			current->symbol;
		++i;
	}
	return (map);
}

int		ft_place_piece(char **map, int map_len, t_tris *current)
{
	t_point xy;

	xy.x = 0;
	xy.y = 0;
	if (current)
	{
		while (xy.y <= map_len)
		{
			if (ft_check(current, map, map_len, &xy) == 1)
			{
				map = ft_insert_piece(current, map, &xy);
				if (ft_place_piece(map, map_len, current->next) == 1)
					return (1);
				map = ft_remove_piece(current, map, map_len);
			}
			xy.x++;
			if (xy.x > map_len)
			{
				xy.x = 0;
				xy.y++;
			}
		}
		return (0);
	}
	return (1);
}

char	**ft_remove_piece(t_tris *piece, char **map, int map_len)
{
	register size_t	i;
	register size_t j;

	i = 0;
	while (i < (size_t)map_len)
	{
		j = 0;
		while (j < (size_t)map_len)
		{
			if (map[i][j] == piece->symbol)
				map[i][j] = '.';
			++j;
		}
		++i;
	}
	return (map);
}
