/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:40:29 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/17 19:46:56 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, void const *content, size_t content_size)
{
	t_list *list;

	list = ft_lstnew(content, content_size);
	list->next = *alst;
	*alst = list;
}
