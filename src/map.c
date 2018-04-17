/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:15:52 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 17:11:02 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  Return size of the map from the number of tetriminos
*/
uint16_t	ft_size_map(uint16_t size)
{
	if (ft_sqrt(size * 4) == 0)
		return (ft_size_map(size + 1));
	return (size * 4);
}

/*
**  Fill the map with dots and \n according to number of tetriminos given
*/
void		ft_fill_map(char **map, uint16_t sqrt)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (i < sqrt)
	{
		j = 0;
		while (j < sqrt)
			map[i][j++] = '.';
		map[i][j] = '\n';		
		++i;
	}
}

/*
**	Return a malloc'd map from number of tetriminos
*/
t_map		*ft_map(uint16_t size)
{
	t_map		*map;
	size_t		i;
	uint16_t	sqrt;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	sqrt = ft_sqrt(ft_size_map(size));
	if (!(map->map = (char**)ft_memalloc((sizeof(char *) * (sqrt + 1)))))
					return (NULL);
	while (i < sqrt)
	{
		if (!(map->map[i] = (char*)ft_memalloc((sizeof(char) * (sqrt + 1)))))
					return (NULL);
		++i;
	}
	ft_fill_map(map->map, sqrt);
	return (map);
}