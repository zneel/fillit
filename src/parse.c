/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/13 12:09:31 by ebouvier         ###   ########.fr       */
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
	char 		*buff;
	uint16_t 	x;
	uint16_t	y;
	size_t		i;
	t_list 	 	*tetris_head;
	t_list		*tetris_current;
	
	while ((bytes = read(fd, &buff, BUFF_SIZE) > 0))
	{
		buff[bytes] = 0;
		tetris_list = (t_list*)malloc(sizeof(t_list));
		while (*buff)
		{
			if (y == 4)
			{
				x = 0;
				y = 0;
			}
			else if (*buff == CHAR_SEP)
			{
				tetris_list->coords[i++];
				++y;
			}
			else if (*buff == CHAR_TTRIS)
			{
				tetris_list->coords[i][0] = x;
				tetris_list->coords[i][1] = y;
				++x;
			}
			++buff;
		}
		if (!tetris_list)
			return (NULL);
		
	}
	close(fd);
	return (tetris_head);
}