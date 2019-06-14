/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:32:59 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/17 20:49:42 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, void const *content, size_t content_size)
{
	t_list *list;

	list = *alst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(content, content_size);
	}
	else
		*alst = ft_lstnew(content, content_size);
}
