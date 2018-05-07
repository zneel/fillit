/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:15:52 by ebouvier          #+#    #+#             */
/*   Updated: 2018/05/07 16:45:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(int size)
{
	int i;

	i = 0;
	while (ft_sqrt(size * 4 + i) == 0)
		++i;
	return (ft_sqrt(size * 4 + i));
}

/*
**  Fill the map with dots and \n according to number of tetriminos given
*/

void	ft_fill_map(char **map, int sqrt)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size_t)sqrt)
	{
		j = 0;
		while (j < (size_t)sqrt)
			map[i][j++] = CHAR_EMPTY;
		++i;
	}
}

/*
**	Return a malloc'd map from number of tetriminos
*/

char	**ft_map(char **map, int size)
{
	int	i;

	i = 0;
	map = ft_memalloc((sizeof(char *) * size + 1));
	while (i < (size_t)size)
		map[i++] = ft_memalloc((sizeof(char) * size + 1));
	ft_fill_map(map, size);
	return (map);
}

/*
**	Return a map bigger map
*/

char	**ft_resize_map(char **map, int map_len)
{
	free(map);
	return (ft_map(map, map_len));
}

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		++i;
	}
}
