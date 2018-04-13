/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:44 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 17:33:11 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tris	*init(char *buffer)
{
	t_tris 	*head;
	size_t	i;
	size_t 	y;
	size_t	x;
	uint16_t tab[4][2];

	if (!buffer)
		return (0);
	if (!(head = (t_tris*)malloc(sizeof(t_tris))))
		return (0);
	i = 0;
	y = 0;
	x = 0;
	while (buffer[i])
	{
		if (buffer[i] == CHAR_SEP)
		{
			x = -1;
			y++;
		}
		else if (buffer[i] == CHAR_TTRIS)
		{
			tab[y][0] = x;
			tab[y][1] = y;
		}
		i++;
		x++;
	}
	ft_push_back(&head, tab);
	return (head);
}
