/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:57:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 12:07:21 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = (char*)malloc(sizeof(*new) * len + 1);
	i = 0;
	if (!new || !s)
		return (NULL);
	while (s[start] && len)
	{
		new[i++] = s[start++];
		--len;
	}
	new[i] = 0;
	return (new);
}
