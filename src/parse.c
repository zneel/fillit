/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/13 18:56:57 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_tetris_valid(char *buff)
{
	size_t	i;
	size_t	hash_count;

	i = 0;
	hash_count = 0;
	while (buff[i])
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
	}
	if (hash_count != 4)
		ft_exit_invalid_piece();
}

void		ft_readfd(int fd)
{
	ssize_t 	bytes;
	char 		buff[BUFF_SIZE];
	
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		ft_tetris_valid(buff);
		ft_putchar(*buff);
		init(buff);
	}
}
