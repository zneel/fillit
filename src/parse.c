/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:39 by ebouvier          #+#    #+#             */
/*   Updated: 2018/04/12 21:51:26 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_readf(char *file)
{
    int     fd;
    size_t  bytes;
    char    buff;
    int     i;
    int     y;

    i = 0;
    y = 0;
    fd = open(file, O_RDONLY | O_APPEND);
    if (fd < 0)
        ft_exit_error();  
    while ((bytes = read(fd, &buff, 1) > 0))
    {
        if (y == 4)
        {
            y = 0;
            i = 0;
            printf("\n");
            continue;
        }
        if (buff == '\n')
        {
            i = 0;
            y++;
            continue;
        }
        else if (buff == CHAR_TTRIS)
        {
            printf("x: %d y: %d\n", i, y);
        }
        i++;
    }
    close(fd);
}