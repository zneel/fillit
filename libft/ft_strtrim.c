/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:13:19 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/09 13:03:34 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	len;
	size_t	end;
	size_t	start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	end = len - 1;
	start = 0;
	while (ft_isws(s[start]))
		++start;
	while (ft_isws(s[end]) && start <= end)
		--end;
	new = (char*)ft_memalloc(end - start + 2);
	if (!new)
		return (NULL);
	ft_strncpy(new, &(s[start]), end - start + 1);
	return (new);
}
