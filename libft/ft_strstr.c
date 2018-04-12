/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:33:15 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/09 11:25:53 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle)
	{
		len = ft_strlen(needle);
		while (ft_strncmp(haystack, needle, len) != 0)
		{
			if (*haystack == '\0')
				return (NULL);
			haystack++;
		}
	}
	return ((char*)haystack);
}
