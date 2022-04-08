/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:31:43 by tpontine          #+#    #+#             */
/*   Updated: 2022/04/08 12:18:21 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(t_tetrimino **map, t_tetrimino **pieces, int count, int grid_size)
{
	int	i;

	i = 0;
	if (*pieces == NULL)
		return (1);
	while (1)
	{
		if (i != 0)
		{
			if (!step(*pieces, grid_size))
			{
				remove_tetrimino_from_map(map, count - 1);
				reset_tetrimino(*pieces);
				return (0);
			}
		}
		if (is_safe(*pieces, *map, count, grid_size))
		{
			toggle(map, *(*pieces), count);
			if (solver(map, pieces + 1, count + 1, grid_size))
				return (1);
		}
		i = 1;
	}
	return (0);
}

t_tetrimino	**create_pieces(t_tetrimino *array, int arr_len)
{
	t_tetrimino	**pieces;
	int			i;

	i = 0;
	pieces = (t_tetrimino **)(malloc(sizeof(t_tetrimino *) * (arr_len + 1)));
	while (i < arr_len)
	{
		pieces[i] = &(array[i]);
		i++;
	}
	pieces[i] = NULL;
	return (pieces);
}

void	solve(t_tetrimino *arr, int grid_size, int arr_len)
{
	t_tetrimino	**pieces;
	t_tetrimino	*map;

	pieces = create_pieces(arr, arr_len);
	map = new_map(arr_len);
	while (grid_size * grid_size < arr_len * 4)
		grid_size++;
	while (1)
	{
		if (!solver(&map, pieces, 0, grid_size))
			grid_size++;
		else
		{
			ft_print_box_ascii(map, arr_len, grid_size);
			break ;
		}	
	}
	free(map);
	free(pieces);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_tetrimino	*arr;	
	int			arr_len;
	int			grid_size;

	arr_len = 0;
	grid_size = 2;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit filename");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	arr = saved_pieces(fd, &arr_len);
	solve(arr, grid_size, arr_len);
	return (0);
}
