/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:30:18 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/17 20:54:06 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->content, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
