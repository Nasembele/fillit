/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:40:25 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/18 17:31:41 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listpointer;

	listpointer = (t_list *)malloc(sizeof(t_list));
	if (listpointer == NULL)
		return (NULL);
	if (content == NULL)
	{
		listpointer->content = NULL;
		listpointer->content_size = 0;
		listpointer->next = NULL;
	}
	else
	{
		listpointer->content = malloc(content_size);
		if (!listpointer->content)
			return (NULL);
		ft_memcpy(listpointer->content, content, content_size);
		listpointer->content_size = content_size;
		listpointer->next = NULL;
	}
	return (listpointer);
}
