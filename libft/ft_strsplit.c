/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:24:48 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/10 16:07:55 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_chars(char const *s, char separator)
{
	size_t i;

	i = 0;
	while (*s != separator && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static	int	ft_count_words(char const *s, char separator)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i + 1] == separator || s[i + 1] == '\0') &&
				s[i] != separator)
			++j;
		++i;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	word;
	size_t	words_count;

	word = 0;
	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	if (!(new = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (word < words_count)
	{
		while (*s && *s == c)
			s++;
		if (!(new[word] = (char*)malloc(sizeof(char) * ft_count_chars(s, c))))
			return (NULL);
		i = 0;
		while (*s && *s != c)
			new[word][i++] = *s++;
		new[word][i] = 0;
		word++;
	}
	new[word] = 0;
	return (new);
}
