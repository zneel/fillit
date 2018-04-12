/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:02:33 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/09 19:21:24 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *curr;
	t_list *tmp;

	if (alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			curr = tmp;
			tmp = tmp->next;
			ft_lstdelone(&curr, del);
		}
		*alst = NULL;
	}
}
