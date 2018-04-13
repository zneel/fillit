/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:44 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 18:56:59 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*init(char *buffer)
{
	t_tris 	*head;
	size_t	i;
	size_t 	y;
	size_t	x;
	uint16_t **tab;

	if (!(tab  = (uint16_t**)malloc(sizeof(uint16_t) * 4)))
		return (0);
	if (!(head = (t_tris*)malloc(sizeof(t_tris))))
		return (0);
	i = 0;
	y = 0;
	x = 0;
	while (buffer[i])
	{
		if (!(*tab = (uint16_t*)malloc(sizeof(uint16_t) * 2)))
			return (0);
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
	//ft_push_back(&head, tab);
	return (head);
}
