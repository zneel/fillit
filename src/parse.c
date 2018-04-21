/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/18 18:51:27 by srequiem         ###   ########.fr       */
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
	size_t	piece;
	int8_t 	xy[4][2];
	int8_t	y;
	int8_t	x;

	i = 0;
	piece = 0;
	x = 0;
	y = 0;
	while (buff[i])
	{
		if (buff[i] == CHAR_SEP)
		{
			x = 0;
			y += 1;
		}
		else if (buff[i] == CHAR_TTRIS)
		{
			xy[piece][0] = x;
			xy[piece][1] = y;
			piece++;
		}
		x++;
		i++;
	}
	ft_lst_push_back(head, ft_reformat_coords(xy), symbol);
}

/*
** Reformat coordonates to the most upper left
*/
int8_t	**ft_reformat_coords(int8_t xy[4][2])
{
	size_t i;
	int8_t or[2];
	int8_t **res;

	i = 0;
	or[0] = xy[0][0];
	or[1] = xy[0][1];
	if (!(res = (int8_t)malloc(sizeof(int8_t*) * 4)))
		return (NULL);
	while(i < 4)
	{
		res[i][0] = xy[i][0] - or[0];
		res[i][1] = xy[i][1] - or[1];
		++i;
	}
	return (res);
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