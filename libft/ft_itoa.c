/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:12:18 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/18 16:24:57 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countnum(int n)
{
	size_t			res;
	unsigned int	num;

	num = n;
	res = 1;
	if (n < 0)
	{
		res++;
		num = -1 * n;
	}
	while (num > 9)
	{
		res++;
		num = num / 10;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char			*res;
	size_t			index;
	unsigned int	tmp;

	index = 0;
	res = (char *)malloc(sizeof(*res) * (countnum(n) + 1));
	if (!res)
		return (0);
	bzero(res, countnum(n) + 1);
	if (n < 0)
	{
		tmp = n * -1;
		res[index] = '-';
	}
	else
		tmp = n;
	index = countnum(n) - 1;
	while (tmp > 9)
	{
		res[index] = tmp % 10 + '0';
		tmp = tmp / 10;
		index--;
	}
	res[index] = tmp % 10 + '0';
	return (res);
}
