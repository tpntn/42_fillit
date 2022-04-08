/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:25:42 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/11 20:51:07 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	size_t	ptr;

	ptr = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[ptr + i] = src[i];
		i++;
	}
	dest[ptr + i] = '\0';
	return (dest);
}
