/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/05/07 16:46:45 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetris_valid(char *buff)
{
	if (check_lines(buff) != TRUE)
		ft_exit_invalid_piece();
	if (check_chars(buff) != TRUE)
		ft_exit_invalid_piece();
	if (check_contigous(buff) != TRUE)
		ft_exit_invalid_piece();
	if (check_hash_count(buff) != TRUE)
		ft_exit_invalid_piece();
	if (count_empty(buff) != TRUE)
		ft_exit_invalid_piece();
}

void	is_sep(char c, int *x, int *y)
{
	if (c == CHAR_SEP)
	{
		*x = -1;
		*y = *y + 1;
	}
}

/*
**	Push a tetris (node) to the linked list with the correct coordonates
*/

void	ft_push_tetris(char *buff, t_tris **head, int symbol)
{
	int	i;
	int	piece;
	int	xy[4][2];
	int	y;
	int	x;

	i = 0;
	piece = 0;
	x = 0;
	y = 0;
	while (buff[i])
	{
		is_sep(buff[i], &x, &y);
		if (buff[i] == CHAR_TTRIS)
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
**	Reformat coordonates to the most upper left
*/

void	ft_reformat_coords(int (*xy)[4][2])
{
	int	i;
	int	or[2];

	i = 0;
	or[0] = (*xy)[0][0];
	or[1] = (*xy)[0][1];
	while (i < 4)
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
	ssize_t	bytes;
	int		i;
	char	buff[BUFF_SIZE];
	t_tris	*head;
	int		symbol;

	head = NULL;
	symbol = 'A';
	i = 0;
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		ft_tetris_valid(buff);
		if (bytes == 20)
			++i;
		if (symbol > 'Z')
			ft_exit_error();
		ft_push_tetris(buff, &head, symbol++);
	}
	if (i != 1)
		ft_exit_invalid_piece();
	return (head);
}
