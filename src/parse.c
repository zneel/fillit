/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/12 23:09:12 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

uint16_t    ft_tetris_valid(t_tris *list)
{
	ft_invalid_piece();   
	return (TRUE);
}

t_list		*ft_readfd(char *file, int fd)
{
	ssize_t 	bytes;
	uint8_t 	buff;
	uint16_t 	x;
	uint16_t	y;
	t_list 	 	*tetris_list;

	while ((bytes = read(fd, &buff, 1) > 0))
	{
		tetris_list = (t_list*)malloc(sizeof(t_list));
		if (!tetris_list)
			return (NULL);
		if (y == 4)
		{
			x = 0;
			y = 0;
		}
		else if (buff == CHAR_SEP)
			y++;
		else if (buff == CHAR_TTRIS)
			x++;
		tetris_list->coords[0] = 
		// else if (buff == CHAR_TTRIS)
		// {
		//     printf("x: %d y: %d\n", i, y);
		// }
		// i++;
	}
	close(fd);
	return (tetris_list);
}