/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:59:05 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/24 11:18:01 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*current;

	current = *alst;
	if (alst)
	{
		while (current)
		{
			del((current)->content, (current)->content_size);
			temp = (current)->next;
			free(current);
			current = temp;
		}
		*alst = NULL;
	}
}
