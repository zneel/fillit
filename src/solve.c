/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/15 19:00:55 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void	ft_fillmap(char **map_str, uint16_t size, uint16_t sqrt)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 1;
	while (i < size + sqrt)
	{
		if (count == sqrt + 1)
		{
			(*map_str)[i] = '\n';
			count = 0;
		}
		else
			(*map_str)[i] = '.';
		++i;
		++count;
	}
}

t_map    *ft_solve(t_tris *tetriminos_list, uint16_t size)
{
	t_map   	*map;
	uint16_t	len;
	uint16_t	sqrt;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);	
	len = ft_size_map(size);
	sqrt = ft_sqrt(len);
	if (!(map->str = (char*)ft_memalloc((sizeof(char) * (len + sqrt) + 1))))
		return (NULL);
	ft_fillmap(&map->str, len, sqrt);
	(void) tetriminos_list;
	return (map);
}

uint16_t ft_size_map(uint16_t size)
{
	if (ft_sqrt(size * 4) == 0)
		return ft_size_map(size + 1);
	return (size * 4);
}

int    ft_place_tetris(t_map *map)
{
	
	(void) map;
	return (0);
}
