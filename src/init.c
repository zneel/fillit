/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:31:44 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 13:49:41 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	init(uint16_t **tab, size_t x, size_t y)
{
	int	i;
	int	j;

	if (!tab)
		return ;
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			tab[i][j] = -1;
			j++;
		}
		i++;
	}
}

int		main(void)
{
	uint16_t	tab[4][2];
	int 		i;
	int 		j;

	init(&tab, 4,2);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			printf("tab[%d][%d] = %d\n", i, j, tab[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

