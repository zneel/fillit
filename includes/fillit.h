/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:37 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/15 11:54:37 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

# define TETRI_MAP_H 4
# define TETRI_MAP_W 5

# define BUFF_SIZE (TETRI_MAP_H * TETRI_MAP_W + 1)
# define CHAR_EMPTY '.'
# define CHAR_TTRIS '#'
# define CHAR_SEP	'\n'
# define ERR_READ "open failed for some reasons"
# define USAGE "usage: ./fillit source_file\n"
# define NOT_VALID_TTRIS "error"
# define TRUE 1
# define FALSE 0

typedef	struct	s_map
{
	uint8_t	m_size_x;
	uint8_t	m_size_y;
	uint8_t	complete;
}				t_map;

typedef struct 	s_tris
{
	uint8_t 		coords[4][2];
	uint8_t			placed;
	struct s_tris	*next;
}				t_tris;

void    	ft_tetris_valid(char *buff);
t_tris		*ft_readfd(int fd);
void		ft_push_back(t_tris **begin_list, uint8_t tab[4][2]);
t_tris		*ft_create_elem(uint8_t tab[4][2]);
void		ft_push_tetri(char *buffer, t_tris **head);
void    	ft_exit_error();
void    	ft_display_usage_too_mny_args();
void	    ft_display_usage_no_file();
void		ft_exit_invalid_piece();
void	    ft_solve(t_tris *tetriminos_list);
void 		ft_print_list(t_tris *list);
#endif
