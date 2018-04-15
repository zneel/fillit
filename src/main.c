/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:59 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/15 15:27:08 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int 		fd;
	t_tris		*tetriminos;
	uint16_t	size;
	t_map		*map;

	if (argc > 2)
		ft_display_usage_too_mny_args();
	if (argc < 2)
		ft_display_usage_no_file();
	if ((fd = open(argv[1], O_RDONLY | O_APPEND)) < 0)
		ft_exit_error();
	tetriminos = ft_readfd(fd);
	ft_print_list(tetriminos);
	size = ft_lstlen(tetriminos);
	ft_putnbr(size);
	ft_putchar('\n');
	map = ft_solve(tetriminos, size);
	free(map);
	ft_lstfree(tetriminos);
	close(fd);
	return (0);
}
