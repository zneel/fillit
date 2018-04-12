/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:34:45 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/04 17:24:40 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dcpy;

	dcpy = dst;
	while (len && *src)
	{
		*dcpy++ = *src++;
		--len;
	}
	while (len)
	{
		*dcpy++ = '\0';
		--len;
	}
	return (dst);
}
