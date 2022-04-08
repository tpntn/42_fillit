/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:36:17 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/15 13:33:05 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	int				slen;
	char			*r;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	r = (char *)malloc(sizeof(char) * slen + 1);
	if (!r)
		return (NULL);
	while (s[i] != '\0')
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
