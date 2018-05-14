/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:59 by ebouvier          #+#    #+#             */
/*   Updated: 2018/05/07 15:21:31 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tris	*tetriminos;
	char	**map;

	if (argc > 2)
		ft_display_usage_too_mny_args();
	if (argc < 2)
		ft_display_usage_no_file();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit_error();
	tetriminos = ft_read(fd);
	if (ft_lstlen(tetriminos) == 0)
		ft_exit_invalid_piece();
	map = ft_solve(tetriminos, ft_size(ft_lstlen(tetriminos)));
	ft_print_map(map);
	free(map);
	ft_lstfree(tetriminos);
	close(fd);
	return (0);
}
