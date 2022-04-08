/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:57:38 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/11 10:08:59 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*csrc;
	char			*cdest;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (char *)src;
	cdest = (char *)dest;
	while (i < n)
	{	
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}
