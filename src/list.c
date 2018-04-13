/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:18:42 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 17:36:04 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tris	*ft_create_elem(uint16_t tab[4][2])
{
	t_tris	*node;

	if (!(node = (t_tris*)malloc(sizeof(*node))))
		return (0);
	node->coords = tab;
	node->next = NULL;
	return (node);
}

void	ft_push_back(t_tris **begin_list, uint16_t tab[4][2])
{
	if (!*begin_list)
		*begin_list = ft_create_elem(tab);
	else if (!(*begin_list)->next)
		(*begin_list)->next = ft_create_elem(tab);
	else
		ft_list_push_back(&(*begin_list)->next, tab);
}
