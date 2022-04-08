/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:11:23 by tpontine          #+#    #+#             */
/*   Updated: 2022/04/07 13:12:44 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetrimino_from_map(t_tetrimino **map, int pos)
{
	if (pos < 0)
		pos = 0;
	ft_memset(*map + pos, 0, sizeof(t_tetrimino));
}

t_tetrimino	*new_map(int arr_len)
{
	t_tetrimino	*map;
	int			i;
	int			c;

	i = 0;
	c = 0;
	map = (t_tetrimino *)malloc(sizeof(t_tetrimino) * arr_len);
	while (i < arr_len)
	{
		while (c < 64)
		{
			ft_memset(&(map[i]).bits[c], 0, sizeof(uint64_t));
			c++;
		}
		i++;
	}
	return (map);
}
