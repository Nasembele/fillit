/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:12:06 by orhoda            #+#    #+#             */
/*   Updated: 2019/04/22 16:49:07 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	checkover(long int res, char num, int sign)
{
	if (sign == 0)
	{
		if ((res * 10 + num - '0') < 0)
			return (-1);
	}
	else
	{
		if (res * -1 * 10 - (num - '0') > 0)
			return (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int			res;
	long int	negative;

	res = 0;
	negative = 0;
	while (*str == '\n' || *str == '\r' || *str == '\v' ||
			*str == ' ' || *str == '\t' || *str == '\f')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (checkover(res, *str, negative) == -1)
			return (-1);
		else if (checkover(res, *str, negative) == 0)
			return (0);
		res = res * 10 + *str - '0';
		str++;
	}
	if (negative == -1)
		res = res * negative;
	return ((int)res);
}
