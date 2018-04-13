/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:18:42 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 18:48:04 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	ft_push_back(t_tris **begin_list, uint16_t **tab)
{
	if (!*begin_list)
		*begin_list = ft_create_elem(tab);
	else if (!(*begin_list)->next)
		(*begin_list)->next = ft_create_elem(tab);
	else
		ft_push_back(&(*begin_list)->next, tab);
}

t_tris	*ft_create_elem(uint16_t **tab)
{
	t_tris	*node;

	if (!(node = (t_tris*)malloc(sizeof(*node))))
		return (0);
	node->coords = tab;
	node->placed = 0;
	node->next = NULL;
	return (node);
}
