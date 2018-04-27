/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/27 13:31:36 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetris_valid(char *buff)
{
	register size_t	i;
	register size_t	hash_count;

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
		if (i % 5 == 4 && buff[i] != '\n')
			ft_exit_invalid_piece();
		++i;
	}
	if (hash_count != 4)
		ft_exit_invalid_piece();
}

/*
**	Push a tetris (node) to the linked list with the correct coordonates
*/
void	ft_push_tetris(char *buff, t_tris **head, int symbol)
{
	register size_t		i;
	register size_t		piece;
	int					xy[4][2];
	register int		y;
	register int		x;

	i = 0;
	piece = 0;
	x = 0;
	y = 0;
	while (buff[i])
	{
		if (buff[i] == CHAR_SEP)
		{
			x = -1;
			y += 1;
		}
		else if (buff[i] == CHAR_TTRIS)
		{
			xy[piece][0] = y;
			xy[piece][1] = x;
			piece++;
		}
		x++;
		i++;
	}
	ft_reformat_coords(&xy);
	ft_lst_push_back(head, xy, symbol);
}

/*
 ** Reformat coordonates to the most upper left
 */

void	ft_reformat_coords(int (*xy)[4][2])
{
	register size_t	i;
	int				or[2];

	i = 0;
	or[0] = (*xy)[0][0];
	or[1] = (*xy)[0][1];
	while(i < 4)
	{
		(*xy)[i][0] = (*xy)[i][0] - or[0];
		(*xy)[i][1] = (*xy)[i][1] - or[1];
		++i;
	}
}

/*
 **	Return a linked list from the fd given
 */

t_tris	*ft_read(int fd)
{
	ssize_t				bytes;
	char				buff[BUFF_SIZE];
	t_tris				*head;
	register uint8_t	symbol;

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
