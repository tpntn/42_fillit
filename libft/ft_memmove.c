/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:31:46 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/11 11:37:30 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*cdest;
	const char		*csrc;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	cdest = (char *)dest;
	csrc = (const char *)src;
	i = 0;
	if (csrc < cdest)
		while (++i <= n)
			cdest[n - i] = csrc[n - i];
	else
		while (n-- > i)
			*(cdest++) = *(csrc++);
	return (dest);
}
