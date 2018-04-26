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
	int		fd;
	t_tris	*tetriminos;
	t_point	*xy;
	char	**map;

	if (argc > 2)
		ft_display_usage_too_mny_args();
	if (argc < 2)
		ft_display_usage_no_file();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit_error();
	if (!(xy =(t_point*)malloc(sizeof(t_point))))
		return (0);
	xy->x = 0;
	xy->y = 0;
	tetriminos = ft_read(fd);
	map = ft_solve(tetriminos, 2, xy);
	ft_print_map(map);
	free(map);
	ft_lstfree(tetriminos);
	close(fd);
	return (0);
}
