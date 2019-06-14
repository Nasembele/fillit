/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:51:33 by soyster           #+#    #+#             */
/*   Updated: 2019/06/13 21:35:09 by orhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_gnl_check(int gnl)
{
	if (gnl == -1)
		exit(-1);
	if (gnl == 0)
		return (0);
	return (1);
}

void	ft_mall_check(void *ptr)
{
	if (ptr == NULL)
		exit(-1);
}

void	ft_print_map(char **map)
{
	int size;
	int i;
	int j;

	i = 0;
	size = ft_strlen(map[0]);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_free_map(char ***map)
{
	int size;

	size = ft_strlen(**map);
	while (size--)
		free((*map)[size]);
	free(*map);
}

void	ft_generate_map(char ***map, int size)
{
	int		i;
	int		j;
	char	**map_tmp;

	i = 0;
	if (*map != NULL)
		ft_free_map(map);
	ft_mall_check(map_tmp = malloc(sizeof(char *) * size));
	while (i < size)
	{
		ft_mall_check(map_tmp[i] = ft_memalloc(sizeof(char) * (size + 1)));
		j = 0;
		while (j < size)
		{
			map_tmp[i][j] = '.';
			j++;
		}
		i++;
	}
	*map = map_tmp;
}
