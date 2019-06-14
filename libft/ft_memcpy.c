/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:10:48 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/22 15:41:18 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *point;

	if (!dst && !src)
		return (NULL);
	point = (unsigned char *)dst;
	while (n--)
		*(point++) = *((unsigned char *)src++);
	return (dst);
}
