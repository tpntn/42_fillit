/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:16:32 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/15 13:35:42 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		r[i] = f(i, (const char)s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
