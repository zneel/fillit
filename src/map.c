/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:15:52 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 18:57:57 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  Return size of the map from the number of tetriminos
*/
int	ft_size_map(int size)
{
	int i;

	i = 0;
	while (ft_sqrt(size * 4 + i) == 0)
		++i;
	return ft_sqrt((size * 4 + i));
}

/*
**  Fill the map with dots and \n according to number of tetriminos given
*/
void		ft_fill_map(char **map, int sqrt)
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
 t_map		*ft_map(int size)
{
	t_map		*map;
	size_t		i;
	int	sqrt;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	sqrt = ft_size_map(size);
	if (!(map->map = (char**)ft_memalloc((sizeof(char *) * (sqrt + 1)))))
					return (NULL);
	while (i < sqrt)
	{
		if (!(map->map[i] = (char*)ft_memalloc((sizeof(char) * (sqrt + 2)))))
					return (NULL);
		++i;
	}
	ft_fill_map(map->map, sqrt);
	return (map);
}

/*
**	Return a map bigger map
*/
t_map		*ft_resize_map(t_map *map)
{
	int size;

	free(map);
	size = ft_map_len(map->map) + 1;
	return ft_map(size);
}

void	ft_print_map(char **map)
{
	size_t i;
	i = 0;
	while(map[i])
		ft_putstr(map[i++]);
}

size_t ft_map_len(char **map)
{
	size_t  i;
	size_t 	res;

	i = 0;
	res = 0;
	while (map[0][i] != '\n')
	{
		++res;
		++i;
	}
	return (res);
}