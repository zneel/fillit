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

char	**ft_solve(t_tris *current, int map_len)
{
	char **map;

	map = ft_map(map, map_len);
	while (ft_place_piece(map, map_len, current) == 0)
	{
		map_len++;
		current->x = 0;
		current->y = 0;
		map = ft_map(map, map_len);
	}
	return (map);
}

int	ft_check(t_tris *current, char **map, int map_len)
{
	size_t i;

	i = 0;
	if (current->x < 0)
		return (FALSE);
	while (i < 4)
	{
		if (current->x + current->xy[i][0] < 0
			|| current->y + current->xy[i][1] < 0
			|| current->x + current->xy[i][0] >= map_len
				|| current->y + current->xy[i][1] >= map_len)
			return (FALSE);
		if (map[current->x + current->xy[i][0]][current->y + current->xy[i][1]]
			!= '.')
				return (FALSE);
		++i;
	}
	return (TRUE);
}

char 	**ft_insert_piece(t_tris *current, char **map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[current->x + current->xy[i][0]][current->y + current->xy[i][1]]
			= (char) current->symbol;
				++i;
	}
	return (map);
}

int		ft_place_piece(char **map, int map_len, t_tris *current)
{
	if (current)
	{
		while (current->x * current->y < map_len * map_len)
		{
			if (ft_check(current, map, map_len) == 1)
			{
				map = ft_insert_piece(current, map);
				if (ft_place_piece(map, map_len, current->next) == 1)
					return (1);
				map = ft_remove_piece(current, map, map_len);
			}
			if (current->x < map_len)
				current->x++;
			else
			{
				current->x = 0;
				current->y++;
			}
		}
		current->x = 0;
		current->y = 0;
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