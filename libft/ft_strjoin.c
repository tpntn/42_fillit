/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:27:46 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/16 17:05:53 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sleni;
	int		slenj;
	char	*new;
	int		i;
	int		j;	

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sleni = ft_strlen(s1);
	slenj = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * sleni + slenj + 1);
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[sleni++] = s2[j++];
	new[sleni] = '\0';
	return (new);
}
