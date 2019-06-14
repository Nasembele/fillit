/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:49:39 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/17 20:54:50 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_num(t_list *begin_list, int nbr)
{
	int i;

	i = 1;
	while (begin_list && i != nbr)
	{
		i++;
		begin_list = begin_list->next;
	}
	if (begin_list && i == nbr)
		return (begin_list);
	else
		return (NULL);
}
