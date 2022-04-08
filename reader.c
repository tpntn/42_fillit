/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpontine <tpontine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:48:08 by jkinnune          #+#    #+#             */
/*   Updated: 2022/04/08 12:12:57 by tpontine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	compare_to_reference(long int tetra)
{	
	const int	pieces[19] = {4369, 15, 802, 113, 275, 71, 785,
		58, 547, 23, 51, 54, 561, 305, 39, 562, 114, 99, 306};
	int			i;

	i = 0;
	if (tetra == 58)
		return (116);
	while (pieces[i] != '\0')
	{
		if (tetra == pieces[i])
			return (tetra);
		if (tetra / 2 == pieces[i])
			return (tetra / 2);
		i++;
	}
	ft_putendl("error");
	exit (0);
}

int	count_bits(int i, long int result, int bit, const char *str)
{
	while (str[i] != '#')
		i++;
	while (i < 20)
	{
		if (str[i] == '#')
		{	
			if (i == 0)
				result++;
			else
			{
				bit = bit * 2;
				result = result + bit;
			}
		}
		else if (str[i] == '.')
		{	
			if (i == 0)
				bit++;
			else
				bit = bit * 2;
		}
		i++;
	}
	return (result);
}

t_tetrimino	parser(char *buf, int i)
{
	char		letter;
	uint64_t	ret;
	uint64_t	*arr;
	t_tetrimino	tetrimino;

	ret = count_bits(0, 0, 1, buf);
	ret = compare_to_reference(ret);
	if (!ret)
		exit(0);
	letter = 65;
	arr = number_to_array(ret);
	ft_memcpy(tetrimino.bits, arr, sizeof(uint64_t) * 64);
	free(arr);
	tetrimino.x = ft_set_x(tetrimino.bits);
	tetrimino.y = ft_set_y(tetrimino.bits);
	tetrimino.x_shift = 0;
	tetrimino.y_shift = 0;
	tetrimino.letter = letter + i;
	i++;
	return (tetrimino);
}

t_tetrimino	*saved_pieces(const int fd, int *i)
{
	int					a;
	int					count;
	int					next;
	static char			buf[548];
	static t_tetrimino	piece_array[26];

	a = *i;
	next = 0;
	count = read(fd, buf, 548);
	buf[count] = '\0';
	validate_input(buf);
	next = 0;
	while (a < 26 && next <= count)
	{
		piece_array[a] = parser(&buf[next], a);
		a++;
		next = next +21;
	}
	*i = a;
	return (piece_array);
}
