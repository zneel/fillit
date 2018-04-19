/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:37 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/18 19:43:05 by srequiem         ###   ########.fr       */
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

typedef	struct		s_map
{
	uint8_t			complete;
	char			**map;
}					t_map;

typedef struct 		s_tris
{
	uint8_t 		coords[4][2];
	uint8_t			placed;
	uint8_t			symbol;
	struct s_tris	*next;
}					t_tris;

int			ft_place_tetris(t_map *map, t_tris *tetris_l);

t_tris		*ft_read_file_des(int fd);
t_tris		*ft_lst_new_elem(int8_t tab[4][2], uint8_t symbol);
t_map   	*ft_map(uint16_t size);
t_map		*ft_resize_map(t_tris *tetris_list);

void		ft_lst_push_back(t_tris **begin_list, int8_t tab[4][2], uint8_t symbol);
void		ft_push_tetris(char *buffer, t_tris **head, uint8_t symbol);
void    	ft_exit_error();
void    	ft_display_usage_too_mny_args();
void	    ft_display_usage_no_file();
void		ft_exit_invalid_piece();
void 		ft_print_list(t_tris *list);
void		ft_lstfree(t_tris *head);
void		ft_is_sep(char buff, size_t *x, size_t *y);
void		ft_fill_map(char **map, uint16_t sqrt);
void    	ft_tetris_valid(char *buff);
void		ft_reformat_coords(int8_t tab[4][2]);
void		ft_print_map(char **map);

uint16_t	ft_lstlen(t_tris *list);
uint16_t	ft_size_map(uint16_t size);
uint8_t		ft_insert_tetris(t_map **map, t_tris *tetris, size_t i);
uint8_t		ft_check(char **map, uint8_t tab[4][2]);
uint8_t 	ft_solve(t_tris *tlist, t_map *map);
u_int8_t 	ft_map_len(char **map, uint8_t x);

#endif
