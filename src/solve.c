/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/15 17:46:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

char	*ft_fillmap(char *str, uint16_t size)
{
	size_t		i;
	size_t		count;
	uint16_t 	sqrt;
	
	i = 0;
	count = 1;
	sqrt = ft_sqrt(size);
	while (i < size + sqrt)
	{
		if (sqrt + 1 == count)
		{
			str[i] = '\n';
			count = 0;
		}
		else
			str[i] = '.';
		++i;
		++count;	
	}
	return (str);
}

t_map    *ft_solve(t_tris *tetriminos_list, uint16_t size)
{
    t_map   	*map;
	uint16_t	len;

	len = ft_size_map(size);
    map = (t_map*)malloc(sizeof(t_map));
	if (!(map->str = (char*)malloc(len * sizeof(char))))
		return (0);
	ft_fillmap(map->str, len);
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
