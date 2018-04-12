/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 00:01:07 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/04 17:17:25 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = len;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i--)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	}
	return (dst);
}
