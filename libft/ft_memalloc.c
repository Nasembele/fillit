/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:38:20 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/16 18:06:05 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *point;

	point = (void *)malloc(size);
	if (point == NULL)
		return (NULL);
	ft_bzero(point, size);
	return (point);
}
