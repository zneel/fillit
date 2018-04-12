/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:27:36 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/06 17:28:23 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen(n);
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	s = (char*)malloc((i * sizeof(*s)) + 1);
	if (!s)
		return (NULL);
	s[i] = 0;
	while (i > 0)
	{
		s[--i] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		s[i] = '-';
	return (s);
}
