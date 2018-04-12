/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 01:58:56 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/04 17:21:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *s1cpy;
	const unsigned char *s2cpy;
	unsigned char		c1;
	unsigned char		c2;

	s1cpy = (unsigned char*)s1;
	s2cpy = (unsigned char*)s2;
	c1 = *s1cpy;
	c2 = *s2cpy;
	while (c1 == c2)
	{
		if (!c1)
			return (c1 - c2);
		c1 = *s1cpy++;
		c2 = *s2cpy++;
	}
	return (c1 - c2);
}
