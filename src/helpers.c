/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:25:54 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/14 13:48:48 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_print_list(t_tris *list)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (list)
    {
        while (i < 4)
        {
            ft_putstr("coords X= ");
            ft_putnbr(list->coords[i][0]);
            ft_putchar('\n');
            ft_putstr("coords Y= ");
            ft_putnbr(list->coords[i][1]);
            ft_putstr("\n\n");
            ++i;
        }
        i = 0;
        list = list->next;
    }
}

void	ft_push_back(t_tris **begin_list, uint16_t tab[4][2])
{
	t_tris *node;
	
	if (!*begin_list)
	{
		*begin_list = ft_create_elem(tab);
		(*begin_list)->next = NULL;
	}
	else
	{
		node = *begin_list;
		while (node->next)
			node = node->next;
		node->next = ft_create_elem(tab);
		node->next->next = NULL;
	}
}

t_tris	*ft_create_elem(uint16_t tab[4][2])
{
	t_tris	*node;

	if (!(node = (t_tris*)malloc(sizeof(*node))))
		return (0);
	ft_memcpy(node->coords, tab, sizeof(uint16_t) * 8);
	node->placed = 0;
	node->next = NULL;
	return (node);
}
