/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:00:44 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/04 17:20:04 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *scpy;

	scpy = (char*)s;
	while (*scpy)
	{
		if (*scpy == c)
			return (scpy);
		++scpy;
	}
	if (c == 0)
		return (scpy);
	return (NULL);
}
