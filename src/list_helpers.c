/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:25:54 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 15:24:29 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Print the t_tris list (Mr Obvious)
*/
void		ft_print_list(t_tris *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		while (i < 4)
		{
			ft_putstr("coords X = ");
			ft_putnbr(list->coords[i][0]);
			ft_putchar('\n');
			ft_putstr("coords Y = ");
			ft_putnbr(list->coords[i][1]);
			ft_putstr("\n");
			ft_putstr("symbol = ");
			ft_putchar(list->symbol);
			ft_putstr("\n");
			ft_putstr("placed = ");
			ft_putnbr(list->placed);
			ft_putstr("\n");
			++i;
		}
		i = 0;
		list = list->next;
	}
}

/*
**	Append an element to the list(Mr Obvious)
*/
void		ft_lst_push_back(t_tris **begin_list, int8_t tab[4][2], uint8_t symbol)
{
	t_tris *node;

	if (!*begin_list)
	{
		*begin_list = ft_lst_new_elem(tab, symbol);
		(*begin_list)->next = NULL;
	}
	else
	{
		node = *begin_list;
		while (node->next)
			node = node->next;
		node->next = ft_lst_new_elem(tab, symbol);
		node->next->next = NULL;
	}
}

/*
**	Create a node (Mr Obvious)
*/
t_tris		*ft_lst_new_elem(int8_t tab[4][2], uint8_t symbol)
{
	t_tris	*node;

	if (!(node = (t_tris*)malloc(sizeof(*node))))
		return (0);
	ft_memcpy(node->coords, tab, sizeof(uint8_t) * 8);
	node->symbol = symbol;
	node->placed = 0;
	node->next = NULL;
	return (node);
}

/*
**	Return len of the list (Mr Obvious)
*/
uint16_t	ft_lstlen(t_tris *list)
{
	uint16_t len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/*
**	Free a list (Mr Obvious)
*/
void		ft_lstfree(t_tris *head)
{
	t_tris	*tmp;
	t_tris	*tmp_next;

	tmp = head;
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
}