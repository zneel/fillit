/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:43:51 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 14:49:10 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  Check if the char is a separator and change x or y accordingly
*/
void		ft_is_sep(char c, size_t *x, size_t *y)
{
	if (c == CHAR_SEP)
	{
		*x = -1;
		*y = *y + 1;
	}
}