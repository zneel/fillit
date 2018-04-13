/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/13 13:48:37 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_tetris_valid(char c)
{
	if (c != CHAR_SEP || c != CHAR_TTRIS || c != CHAR_EMPTY)
		ft_exit_invalid_piece();
}

t_list		*ft_readfd(int fd)
{
	ssize_t 	bytes;
	char 		*buff;
	// uint16_t 	x;
	// uint16_t	y;
	// size_t		i;
	t_list 	 	*tetris_head;
	// t_list		*tetris_current;
	
	while ((bytes = read(fd, &buff, BUFF_SIZE) > 0))
	{
		buff[bytes] = '\0';
		tetris_head = (t_list*)malloc(sizeof(t_list));
		if (!tetris_head)
			return (NULL);
		while (*buff)
		{
			ft_tetris_valid(*buff);
			ft_putchar(*buff);
		// 	if (y == 4)
		// 	{
		// 		x = 0;
		// 		y = 0;
		// 	}
		// 	else if (*buff == CHAR_SEP)
		// 	{
		// 		tetris_list->coords[i++];
		// 		++y;
		// 	}
		// 	else if (*buff == CHAR_TTRIS)
		// 	{
		// 		tetris_list->coords[i][0] = x;
		// 		tetris_list->coords[i][1] = y;
		// 		++x;
		// 	}
			++buff;
		}
	}
	return (tetris_head);
}