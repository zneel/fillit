/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 00:59:40 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 16:51:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1ptr;
	const unsigned char *s2ptr;

	s1ptr = (const unsigned char*)s1;
	s2ptr = (const unsigned char*)s2;
	while (n--)
	{
		if (*s1ptr != *s2ptr)
			return (*s1ptr - *s2ptr);
		++s1ptr;
		++s2ptr;
	}
	return (0);
}
