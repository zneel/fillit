/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:16:11 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/15 13:40:56 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map    *ft_solve(t_tris *tetriminos_list)
{
    t_map   *map;

    map = (t_map*)malloc(sizeof(t_map));
    (void) tetriminos_list;
    
    return (map);
}


int    ft_place_tetris(t_map *map)
{
        (void)map;
    return (0);
}
