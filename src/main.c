/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:59 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/18 18:39:47 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_tris		*tetriminos;
	uint16_t	size;
	t_map		*map;

	if (argc > 2)
		ft_display_usage_too_mny_args();
	if (argc < 2)
		ft_display_usage_no_file();
	if ((fd = open(argv[1], O_RDONLY | O_APPEND)) < 0)
		ft_exit_error();
	tetriminos = ft_read_file_des(fd);
	size = ft_lstlen(tetriminos);
	map = ft_map(size);
	ft_place_tetris(map, tetriminos);
	//ft_print_list(tetriminos);
	free(map->map);
	free(map);
	ft_lstfree(tetriminos);
	close(fd);
	return (0);
}
