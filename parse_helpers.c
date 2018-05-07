/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:31:41 by ebouvier          #+#    #+#             */
/*   Updated: 2018/05/07 16:45:01 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_contigous(char *buff)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i + 1] == CHAR_TTRIS && cpy[i] == CHAR_TTRIS)
			++j;
		if (cpy[i - 1] == CHAR_TTRIS && cpy[i] == CHAR_TTRIS)
			++j;
		if (cpy[i + 5] == CHAR_TTRIS && cpy[i] == CHAR_TTRIS)
			++j;
		if (cpy[i - 5] == CHAR_TTRIS && cpy[i] == CHAR_TTRIS)
			++j;
		++i;
	}
	if (j >= 6)
		return (TRUE);
	return (FALSE);
}

int	check_hash_count(char *buff)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i] == CHAR_TTRIS)
			++j;
		++i;
	}
	if (j != 4)
		return (FALSE);
	return (TRUE);
}

int	check_chars(char *buff)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i] != CHAR_SEP && cpy[i] != CHAR_TTRIS &&
				cpy[i] != CHAR_EMPTY)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	check_lines(char *buff)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i] == '\n')
			++j;
		if (i % 5 == 4 && cpy[i] != '\n')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	count_empty(char *buff)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	cpy = buff;
	while (cpy[i])
	{
		if (cpy[i] == CHAR_EMPTY)
			++j;
		++i;
	}
	if (j != 12)
		return (FALSE);
	return (TRUE);
}
