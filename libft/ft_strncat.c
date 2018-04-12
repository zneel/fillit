/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:58:31 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 16:35:35 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1cpy;
	size_t	len;

	s1cpy = s1;
	len = ft_strlen(s1cpy);
	while (*s2 && n)
	{
		s1cpy[len++] = *s2++;
		--n;
	}
	s1cpy[len] = '\0';
	return (s1cpy);
}
