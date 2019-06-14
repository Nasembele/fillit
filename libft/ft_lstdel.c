/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:55:29 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/22 15:35:15 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *tmp;

	list = *alst;
	if (del == NULL)
		return ;
	while (list)
	{
		del(list->content, list->content_size);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*alst = NULL;
}
