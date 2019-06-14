/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:51:27 by orhoda            #+#    #+#             */
/*   Updated: 2019/06/10 19:51:31 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}
