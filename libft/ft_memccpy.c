/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:32:55 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/16 12:54:42 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*point;
	const unsigned char	*psrc;

	point = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	while (n--)
	{
		if (*psrc == (unsigned char)c)
		{
			*point = *psrc;
			return ((void *)++point);
		}
		*(point++) = *(psrc++);
	}
	return (NULL);
}
