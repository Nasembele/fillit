/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:47:16 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/17 19:49:22 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *begin_list)
{
	int res;

	res = 0;
	if (begin_list)
		while (begin_list)
		{
			res++;
			begin_list = begin_list->next;
		}
	return (res);
}
