/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:37:51 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/15 18:44:31 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(unsigned char *)(s1++) != *((unsigned char *)s2++))
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	return (0);
}
