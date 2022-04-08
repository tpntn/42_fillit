/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:52:57 by jkinnune          #+#    #+#             */
/*   Updated: 2022/04/07 13:15:40 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_tetrimino
{
	uint64_t	bits[64];
	char		letter;
	int			x_shift;
	int			y_shift;
	int			x;
	int			y;

}	t_tetrimino;

t_tetrimino		*saved_pieces(const int fd, int *i);
void			ft_print_box_ascii(t_tetrimino *array, int count,
					int grid_size);
int				validate_lines_and_char(char *s, int i, int count, int lines);
int				validate_tetros(char *s, int i, int connection, int k);
void			validate_input(char *buffer);
uint64_t		*number_to_array(unsigned long n);
int				ft_set_x(uint64_t *array);
int				ft_set_y(uint64_t *array);
void			ft_perform_x_shift(t_tetrimino *t);
void			ft_perform_y_shift(t_tetrimino *t);
int				is_safe(t_tetrimino *t, t_tetrimino *map,
					int count, int grid_size);
void			reset_tetrimino(t_tetrimino *t);
int				step(t_tetrimino *t, int grid_size);
int				toggle(t_tetrimino **map, t_tetrimino t, int pos);
void			remove_tetrimino_from_map(t_tetrimino **map, int pos);
t_tetrimino		*new_map(int arr_len);
int				compare_to_reference(long int tetra);
int				count_bits(int i, long int result, int bit,
					const char *str);
t_tetrimino		parser(char *buf, int i);
t_tetrimino		*saved_pieces(const int fd, int *i);

#endif
