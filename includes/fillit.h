/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:37 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/13 15:58:38 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>

# define TETRI_MAP_H 4
# define TETRI_MAP_W 4
# define BUFF_SIZE (TETRI_MAP_H * TETRI_MAP_W + 1)
# define CHAR_EMPTY '.'
# define CHAR_TTRIS '#'
# define CHAR_SEP	'\n'
# define ERR_READ "\033[31mopen failed for some reasons"
# define USAGE "\033[31musage: ./fillit entry_file\n"
# define TRUE 1
# define FALSE 0

typedef struct 	s_tris
{
	uint16_t 	coords[4][2];
	t_list 		*next;
}				t_tris;

void		ft_push_back(t_tris **begin_list, uint16_t tab[4][2]);
t_tris		*ft_create_elem(uint16_t tab[4][2]);
void		init(uint16_t tab[4][2]);
void		ft_tetris_valid(char c);
t_list		*ft_readfd(int fd);
void    	ft_exit_error();
void    	ft_display_usage_too_mny_args();
void	    ft_display_usage_no_file();
void		ft_exit_invalid_piece();
#endif
