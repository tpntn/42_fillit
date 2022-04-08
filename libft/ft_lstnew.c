/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkinnune <jkinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:36:13 by jkinnune          #+#    #+#             */
/*   Updated: 2021/11/24 13:29:09 by jkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
		head->next = NULL;
		return (head);
	}
	head->content = malloc(content_size);
	if (!head->content)
		return (0);
	ft_memmove(head->content, content, content_size);
	head->content_size = content_size;
	head->next = NULL;
	return (head);
}
