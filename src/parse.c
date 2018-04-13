/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/13 22:37:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_tetris_valid(char *buff, ssize_t bytes)
{
	size_t	i;
	size_t	hash_count;

	i = 0;
	hash_count = 0;
	ft_putnbr(bytes);
	if (bytes > 21)
		ft_exit_invalid_piece();
	while (i < (size_t)bytes)
	{
		if (buff[i] == CHAR_TTRIS)
		{
			if (buff[i + 1] != CHAR_TTRIS && buff[i - 1] != CHAR_TTRIS &&
					buff[i + 5] != CHAR_TTRIS && buff[i - 5] != CHAR_TTRIS)
				ft_exit_invalid_piece();
		}
		if (buff[i] == CHAR_TTRIS)
			++hash_count;
		if (buff[i] != CHAR_SEP && buff[i] != CHAR_TTRIS &&
			buff[i] != CHAR_EMPTY)
			ft_exit_invalid_piece();
		++i;
		if ( i % 5 == 4 && buff[i] != '\n')
			ft_exit_invalid_piece();
	}
	if (hash_count != 4)
		ft_exit_invalid_piece();
}

void	ft_push_tetri(char *buffer, t_tris **head, ssize_t bytes)
{
	size_t	i;
	size_t 	y;
	size_t	x;
	size_t	piece;
	uint16_t tab[4][2];
	
	y = 0;
	x = 0;
	i = 0;
	piece = 0;
	while (i++ < (size_t)bytes)
	{
		if (buffer[i] == CHAR_SEP)
		{
			y++;
			x = -1;
		}
		else if (buffer[i] == CHAR_TTRIS)
		{
			tab[piece][0] = x;
			tab[piece][1] = y;
			piece++;
		}
		x++;
	}
	ft_push_back(head, tab);
}

t_tris		*ft_readfd(int fd)
{
	ssize_t 	bytes;
	char 		buff[BUFF_SIZE];
	t_tris		*head;
	
	head = NULL;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		ft_tetris_valid(buff, bytes);
		ft_push_tetri(buff, &head, bytes);
	}
	return (head);
}
