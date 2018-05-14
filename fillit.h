/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:30:37 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/10 12:50:38 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>

# define TETRI_MAP_H 4
# define TETRI_MAP_W 5

# define BUFF_SIZE (TETRI_MAP_H * TETRI_MAP_W + 1)
# define CHAR_EMPTY '.'
# define CHAR_TTRIS '#'
# define CHAR_SEP	'\n'
# define USAGE "usage: ./fillit source_file\n"
# define NOT_VALID_TTRIS "error\n"
# define TRUE 1
# define FALSE 0

typedef struct		s_tris
{
	int				symbol;
	int				xy[4][2];
	struct s_tris	*next;
}					t_tris;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				is_sep(char c, register int *x, register int *y);
t_tris				*ft_read(int fd);
t_tris				*ft_lst_new_elem(int xy[4][2], int symbol);

char				**ft_resize_map(char **map, int map_len);
char				**ft_map(char **map, int size);
char				**ft_remove_piece(t_tris *piece, char **map, int map_len);
char				**ft_insert_piece(t_tris *current, char **map, t_point *xy);
char				**ft_solve(t_tris *current, int map_len);

void				ft_lst_push_back(t_tris **head, int xy[4][2], int symbol);
void				ft_push_tetris(char *buffer, t_tris **head, int symbol);
void				ft_exit_error();
void				ft_display_usage_too_mny_args();
void				ft_display_usage_no_file();
void				ft_exit_invalid_piece();
void				ft_print_list(t_tris *list);
void				ft_lstfree(t_tris *head);
void				ft_fill_map(char **map, int sqrt);
void				ft_tetris_valid(char *buff);
void				ft_print_map(char **map);
void				ft_reformat_coords(int (*xy)[4][2]);

int					ft_lstlen(t_tris *list);
int					ft_check(t_tris *current, char **map, int map_len
					, t_point *xy);
int					ft_place_piece(char **map, int map_len, t_tris *current);
int					ft_size(int size);
int					check_contigous(char *buff);
int					check_hash_count(char *buff);
int					check_chars(char *buff);
int					check_lines(char *buff);
int					count_empty(char *buff);
#endif
