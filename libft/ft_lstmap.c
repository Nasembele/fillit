/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:31:17 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/22 16:50:16 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*newlist;
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return (NULL);
	if (f == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(newlist = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	free(tmp);
	start = newlist;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(newlist->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		free(tmp);
		lst = lst->next;
		newlist = newlist->next;
	}
	return (start);
}
