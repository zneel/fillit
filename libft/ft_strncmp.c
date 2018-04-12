/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:45:51 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 18:30:34 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s1cpy;
	const unsigned char *s2cpy;
	unsigned char		c1;
	unsigned char		c2;

	s1cpy = (unsigned char*)s1;
	s2cpy = (unsigned char*)s2;
	c1 = *s1cpy;
	c2 = *s2cpy;
	if (n == 0)
		return (0);
	while (c1 == c2 && n)
	{
		if (!c1)
			return (c1 - c2);
		c1 = *s1cpy++;
		c2 = *s2cpy++;
		--n;
	}
	return (c1 - c2);
}
