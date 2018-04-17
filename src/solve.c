/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 13:22:57 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fillmap(char **map_str, uint16_t size, uint16_t sqrt)
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

t_map		*ft_solve(t_tris *tetriminos_list, uint16_t size)
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
	ft_fillmap(&map->str, len, sqrt);
	(void)tetriminos_list;
	return (map);
}

uint16_t	ft_size_map(uint16_t size)
{
	if (ft_sqrt(size * 4) == 0)
		return (ft_size_map(size + 1));
	return (size * 4);
}

int			ft_sizeline(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int			ft_place_tetris(t_map *map ,t_tris *tetriminos, uint16_t size)
{
	//map = ft_solve(tetriminos, size + 1);
	t_tris	*tmp;
	uint8_t	nbr;
	int		i;
	int		size_line;

	//ft_putnbr(size);
	tmp = tetriminos;
	while (tetriminos)
	{
		size_line = ft_sizeline(map->str);
		i = 0;
		while (i < 4)
		{
			nbr = tetriminos->coords[i][0] + (tetriminos->coords[i][1] * (size_line + 1));
			//if (nbr >= ft_strlen(map->str))
			//	map = ft_solve(tetriminos, size + 1);
			 map->str[nbr] = tetriminos->symbol;
			i++;
		}
		tetriminos->placed = 1;
		tetriminos = tetriminos->next;
	}

	ft_putstr(map->str);
	(void)size;
	(void)tetriminos;
	return (0);
}
