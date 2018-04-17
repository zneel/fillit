/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:15:52 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 14:49:04 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Return a malloc'd map from number of tetriminos
*/
t_map		*ft_map(uint16_t size)
{
	t_map		*map;
	uint16_t	len;
	uint16_t	sqrt;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	len = ft_size_map(size);
	sqrt = ft_sqrt(len);
	if (!(map->str = (char*)ft_memalloc((sizeof(char) * (len + sqrt) + 1))))
		return (NULL);
	ft_fill_map(&map->str, len, sqrt);
	return (map);
}

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
** Return size of map line to a \n
*/
uint16_t	ft_size_line(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

/*
**  Fill the map with dots and \n according to number of tetriminos given
*/
void		ft_fill_map(char **map_str, uint16_t size, uint16_t sqrt)
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
