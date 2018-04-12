/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:37 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/12 23:03:17 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 4096
# define CHAR_EMPTY '.'
# define CHAR_TTRIS '#'
# define CHAR_SEP	'\n'
# define ERR_READ "\033[31mopen failed for some reasons"
# define USAGE "\033[31musage: ./fillit entry_file\n"
# define TRUE 1
# define FALSE 0

typedef struct 	s_tris
{
	uint16_t 	coords[8];
	t_list 		*next;
}				t_tris;

uint16_t	ft_tetris_valid()
void    	ft_readf(char *file);
void    	ft_exit_error();
void    	ft_display_usage_too_mny_args();
void	    ft_display_usage_no_file();
void		ft_invalid_piece();
#endif
