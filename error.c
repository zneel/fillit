/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:40:54 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/17 21:51:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_exit_error(void)
{
	ft_putstr(ERR_READ);
	exit(1);
}

void	ft_display_usage_no_file(void)
{
	ft_putstr(USAGE);
	exit(1);
}

void	ft_display_usage_too_mny_args(void)
{
	ft_putstr("\033[31mToo many arguments\n");
	ft_putstr(USAGE);
	exit(1);
}

void	ft_exit_invalid_piece(void)
{
	ft_putstr(NOT_VALID_TTRIS);
	exit(1);
}
