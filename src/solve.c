/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/15 15:13:05 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_fillmap(char *str, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < size - 1)
	{
		if (count == 4)
		{
			str[i] = '\n';
			count = -1;
		}
		else
			str[i] = '.';
		i++;
		count++;
	}
	str[i] = '\0';
	return (str);
}
t_map    *ft_solve(t_tris *tetriminos_list, uint16_t size)
{
    t_map   	*map;
	uint16_t	len;

	len = (size * size) + size + 1;
    map = (t_map*)malloc(sizeof(t_map));
	if (!(map->str = (char*)malloc(len * sizeof(char))))
		return (0);
	
    (void) tetriminos_list;

    return (map);
}


int    ft_place_tetris(t_map *map)
{
        (void)map;
    return (0);
}
