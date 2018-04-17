/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 19:10:36 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_tetris_valid(char *buff)
{
	size_t	i;
	size_t	hash_count;
	char	*cpy;

	i = 0;
	hash_count = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i] == CHAR_TTRIS)
		{
			if (cpy[i + 1] != CHAR_TTRIS && cpy[i - 1] != CHAR_TTRIS &&
					cpy[i + 5] != CHAR_TTRIS && cpy[i - 5] != CHAR_TTRIS)
				ft_exit_invalid_piece();
		}
		if (cpy[i] == CHAR_TTRIS)
			++hash_count;
		if (cpy[i] != CHAR_SEP && cpy[i] != CHAR_TTRIS &&
				cpy[i] != CHAR_EMPTY)
			ft_exit_invalid_piece();
		if (i % 5 == 4 && cpy[i] != '\n')
			ft_exit_invalid_piece();
		++i;
	}
	if (hash_count != 4)
		ft_exit_invalid_piece();
}


/*
**	Push a tetris (node) to the linked list with the correct coordonates
*/
void		ft_push_tetris(char *buff, t_tris **head, uint8_t symbol)
{
	size_t	i;
	size_t	y;
	size_t	x;
	size_t	piece;
	uint8_t	tab[4][2];

	y = 0;
	x = 0;
	i = -1;
	piece = 0;
	while (buff[++i])
	{
		if (buff[i] == CHAR_SEP)
			ft_is_sep(buff[i], &x, &y);
		else if (buff[i] == CHAR_TTRIS)
		{
			tab[piece][0] = x;
			tab[piece][1] = y;
			piece++;
		}
		x++;
	}
	ft_lst_push_back(head, tab, symbol);
}

/*
**	Return a linked list from the fd given
*/
t_tris		*ft_read_file_des(int fd)
{
	ssize_t		bytes;
	char		buff[BUFF_SIZE];
	t_tris		*head;
	uint8_t		symbol;

	head = NULL;
	symbol = 'A';
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		ft_tetris_valid(buff);
		if (symbol > 'Z')
			ft_exit_error();
		ft_push_tetris(buff, &head, symbol++);
	}
	return (head);
}
