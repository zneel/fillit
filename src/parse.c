/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/20 14:21:25 by macbook          ###   ########.fr       */
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
	int8_t	tab[4][2];

	y = 0;
	x = 0;
	i = 0;
	piece = 0;
	while (buff[i])
	{
		if (buff[i] == CHAR_SEP)
			ft_is_sep(buff[i], &x, &y);
		else if (buff[i] == CHAR_TTRIS)
		{
			tab[piece][0] = (int8_t)x;
			tab[piece][1] = (int8_t)y;
			piece++;
		}
		x++;
		i++;
	}
	ft_reformat_coords(tab);
	ft_lst_push_back(head, tab, symbol);
}

/*
** Reformat coordonates to the most upper left
*/
void	ft_reformat_coords(int8_t tab[4][2])
{
	size_t i;
	int8_t or[2];

	i = 0;
	or[0] = tab[0][0];
	or[1] = tab[0][1];
	while(i < 4)
	{
		tab[i][0] = tab[i][0] - or[0];
		tab[i][1] = tab[i][1] - or[1];
		++i;
	}
}

/*
**	Check if the last line is an empty line
**	Return an error message in this case
*/

void	ft_check_last(int fd)
{
	ssize_t	bytes;
	char	buff[2];

	while ((bytes = read(fd, &buff, 2)) > 0)
	{
		;
	}
	if (ft_strcmp(buff, "\n\n") == 0)
		ft_exit_invalid_piece();
	close(fd);
}

/*
**	Return a linked list from the fd given
*/
t_tris		*ft_read_file_des(int fd, char *argv1)
{
	ssize_t		bytes;
	char		buff[BUFF_SIZE];
	t_tris		*head;
	uint8_t		symbol;

	head = NULL;
	symbol = 'A';
	ft_check_last(fd);      //Permet de verifier que l'on ne fini pas sur une ligne vide (ou plusieurs)
	if ((fd = open(argv1, O_RDONLY | O_APPEND)) < 0) //Open again car close dans la func. ft_check_last
		ft_exit_error();
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
