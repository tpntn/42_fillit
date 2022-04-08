/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:01:03 by tpontine          #+#    #+#             */
/*   Updated: 2022/04/07 13:03:18 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_box_ascii(t_tetrimino *array, int count, int grid_size)
{
	int		i;
	char	letter;
	int		index;
	int		a;

	a = 0;
	i = 0;
	while (i < ((grid_size * grid_size)))
	{
		letter = '.';
		if (a >= grid_size)
			a = 0;
		index = 0;
		while (index < count)
		{
			if ((array[index].bits[(i / grid_size)] >> a) & 1)
				letter = array[index].letter;
			index++;
		}
		ft_putchar(letter);
		if ((i + 1) % grid_size == 0)
			ft_putchar('\n');
		i++;
		a++;
	}
}

int	is_safe(t_tetrimino *t, t_tetrimino *map, int count, int grid_size)
{
	int	i;
	int	row;

	if (t->x > grid_size || t->y > grid_size)
		return (0);
	if (count == 0)
		return (1);
	i = 0;
	while (i < count)
	{
		row = 0;
		while (row < 64)
		{
			if (t->bits[row] & map[i].bits[row])
				return (0);
			row++;
		}
		i++;
	}
	return (1);
}

void	reset_tetrimino(t_tetrimino *t)
{
	int	row;

	row = 0;
	while (row < 64)
	{
		t->bits[row] >>= t->x_shift;
		row++;
	}
	t->x_shift = 0;
	row = 0;
	while (row < 64)
	{
		if (row + t->y_shift < 64)
			t->bits[row] = t->bits[row + t->y_shift];
		else
			t->bits[row] = 0;
		row++;
	}
	t->y_shift = 0;
}

int	step(t_tetrimino *t, int grid_size)
{
	if (grid_size - t->x - t->x_shift <= 0
		&& grid_size - t->y - t->y_shift <= 0)
		return (0);
	if (grid_size - t->x - t->x_shift > 0)
		ft_perform_x_shift(t);
	else
		ft_perform_y_shift(t);
	return (1);
}

int	toggle(t_tetrimino **map, t_tetrimino t, int pos)
{
	if (ft_memcpy(*map + pos, &t, sizeof(t_tetrimino)))
		return (1);
	return (0);
}
