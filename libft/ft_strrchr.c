/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:15:49 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/04 17:24:30 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *scpy;
	char *ptr;

	scpy = (char*)s;
	ptr = NULL;
	while (*scpy)
	{
		if (*scpy == c)
			ptr = scpy;
		++scpy;
	}
	if (c == 0)
		return (scpy);
	return (ptr);
}
