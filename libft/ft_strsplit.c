/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 08:52:56 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/24 17:38:50 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_arrfree(char **res, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(res[i]);
	free(res);
	return (NULL);
}

static	size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (*s)
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			wc++;
		}
		s++;
	}
	return (wc);
}

static char	**splitter(char **res, char const *s, size_t wcount, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = -1;
	while (++j < wcount)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = ft_strsub(s, start, i - start);
		if (res[j] == NULL)
			return (ft_arrfree(res, j));
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	wcount;
	char	**res;

	if (!s || !c)
		return (NULL);
	wcount = wordcount(s, c);
	res = malloc((sizeof(char *) * (wcount + 1)));
	if (!res)
		return (NULL);
	res = splitter(res, s, wcount, c);
	return (res);
}
