/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:33:44 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/10 16:16:59 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_head;
	t_list *prev;
	t_list *next;

	new_head = (t_list*)malloc(sizeof(t_list));
	if (!new_head)
		return (NULL);
	if (f && lst)
	{
		new_head = (*f)(lst);
		prev = new_head;
		lst = lst->next;
		while (lst)
		{
			next = (t_list*)malloc(sizeof(t_list));
			if (!next)
				return (NULL);
			next = (*f)(lst);
			prev->next = next;
			prev = next;
			lst = lst->next;
		}
	}
	return (new_head);
}
