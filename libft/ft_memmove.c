/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:58:21 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/22 15:43:00 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	i = 0;
	if (pdst > psrc)
		while (i++ < len)
			pdst[len - i] = psrc[len - i];
	else
		while (i++ < len)
			*(pdst++) = *(psrc++);
	return (dst);
}
