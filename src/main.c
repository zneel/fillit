/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:59 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/14 13:14:06 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	int fd;
	t_tris *tetriminos;
	
	if (argc > 2)
		ft_display_usage_too_mny_args();
	if (argc < 2)
		ft_display_usage_no_file();
	if ((fd = open(argv[1], O_RDONLY | O_APPEND)) < 0)
		ft_exit_error();
	tetriminos = ft_readfd(fd);
	ft_print_list(tetriminos);
	ft_solve(tetriminos);
	close(fd);
	return (0);
}
