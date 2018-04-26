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

char	**ft_solve(t_tris *current, int map_len, t_point *xy)
{
	char **map;

	map = ft_map(map, map_len);
	while (ft_place_piece(map, map_len, current, xy) == 0)
	{
		ft_putchar('\n');
		ft_print_map(map);
		ft_putchar('\n');
		map_len++;
		map = ft_resize_map(map, map_len);
		xy->x = 0;
		xy->y = 0;
	}
	return (map);
}

int	ft_check(t_tris *current, char **map, int map_len, t_point *xy)
{
	size_t i;

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
		if (map[xy->x + current->xy[i][1]][xy->y + current->xy[i][0]] != '.')
				return (FALSE);
		++i;
	}
	return (TRUE);
}

char 	**ft_insert_piece(t_tris *current, char **map, t_point *xy)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[xy->x + current->xy[i][1]][xy->y + current->xy[i][0]] = (char) current->symbol;
				++i;
	}
	return (map);
}

int		ft_place_piece(char **map, int map_len, t_tris *current, t_point *xy)
{
	if (current)
	{
		while (xy->y < map_len)
		{
			if (ft_check(current, map, map_len, xy) == 1)
			{
				map = ft_insert_piece(current, map, xy);
				if (ft_place_piece(map, map_len, current->next, xy) == 1)
					return (1);
				map = ft_remove_piece(current, map, map_len);
			}
			if (xy->x < map_len)
				xy->x++;
			else
			{
				xy->x = 0;
				xy->y++;
			}
		}
		return (0);
	}
	return (1);
}

char **ft_remove_piece(t_tris *piece, char **map, int map_len)
{
	size_t	i;
	size_t 	j;

	i = 0;
	while(i < map_len)
	{
		j = 0;
		while (j < map_len)
		{
			if (map[i][j] == piece->symbol)
				map[i][j] = '.';
			++j;
		}
		++i;
	}
	return (map);
}