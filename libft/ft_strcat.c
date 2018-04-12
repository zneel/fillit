/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:58:38 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 14:02:03 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s1cpy;
	size_t	len;

	s1cpy = s1;
	len = ft_strlen(s1cpy);
	while (*s2)
		s1cpy[len++] = *s2++;
	s1cpy[len] = '\0';
	return (s1cpy);
}
