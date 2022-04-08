/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:16:26 by jkinnune          #+#    #+#             */
/*   Updated: 2022/04/07 13:00:07 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_set_y(uint64_t *array)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < 64)
	{
		if (array[i] != 0)
			y++;
		i++;
	}
	return (y);
}

int	ft_set_x(uint64_t *array)
{
	int	i;
	int	c;
	int	x;

	i = 0;
	x = 1;
	while (i < 64)
	{
		c = 0;
		while (c < 64)
		{
			if (array[i] >> c & 1 && c >= x)
				x++;
			c++;
		}
		i++;
	}
	return (x);
}

uint64_t	*number_to_array(unsigned long n)
{
	uint64_t		*array;
	unsigned int	i;
	unsigned int	mask;
	uint64_t		result;

	array = (uint64_t *)malloc(sizeof(uint64_t) * 64);
	if (!array)
		return (NULL);
	i = 0;
	while (i < 64)
	{
		ft_memset(&array[i], 0, sizeof(uint64_t));
		i++;
	}
	i = 0;
	mask = 15;
	while (i < 4)
	{
		result = (n & mask) >> (i * 4);
		mask <<= 4;
		array[i] = result;
		i++;
	}
	return (array);
}

void	ft_perform_x_shift(t_tetrimino *t)
{
	int	row;

	row = 0;
	while (row < 64)
	{
		t->bits[row] <<= 1;
		row++;
	}
	t->x_shift++;
}

void	ft_perform_y_shift(t_tetrimino *t)
{
	int	row;

	row = 63;
	while (row > 0)
	{
		t->bits[row] = t->bits[row - 1];
		t->bits[row] >>= t->x_shift;
		row--;
	}
	t->bits[0] = 0;
	t->x_shift = 0;
	t->y_shift++;
}
