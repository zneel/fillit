/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 21:40:54 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/12 21:55:28 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_exit_error()
{
    ft_putstr(ERR_READ);
    exit(1);
}

void ft_display_usage_no_file()
{
    ft_putstr(USAGE);
    exit(1);
}

void ft_display_usage_too_mny_args()
{
    ft_putstr("\033[31mToo many arguments\n");
    ft_putstr(USAGE);
    exit(1);
}