/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:51:33 by soyster           #+#    #+#             */
/*   Updated: 2019/06/12 17:50:14 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		*ft_define_coordinates(const char *tetra)
{
	int *result;
	int i;
	int j;

	i = 0;
	j = 0;
	ft_mall_check(result = malloc(sizeof(int) * 30));
	while (tetra[i] != '\0')
	{
		if (tetra[i] != '.' && tetra[i] != '\n')
		{
			result[j] = i;
			j++;
		}
		i++;
	}
	return (result);
}

int		ft_read_gnl(char *str, char **tmp, char *letter, t_flist **all_lists)
{
	char	*tmp_leak;

	if (*str != '\0')
	{
		ft_mall_check(tmp_leak = ft_strjoin(*tmp, str));
		ft_strdel(tmp);
		*tmp = tmp_leak;
		ft_mall_check(tmp_leak = ft_strjoin(*tmp, "\n"));
		ft_strdel(tmp);
		*tmp = tmp_leak;
	}
	else
	{
		if (ft_strlen(*tmp) != 20)
		{
			ft_strdel(tmp);
			return (0);
		}
		ft_lst_back(all_lists, *letter, *tmp, ft_define_coordinates(*tmp));
		ft_mall_check(*tmp = ft_strdup(""));
		(*letter)++;
	}
	return (1);
}

int		ft_read_tet(t_flist **all_lists, char *filename)
{
	int		fd;
	char	letter;
	char	*str;
	char	*tmp;

	str = NULL;
	letter = 'A';
	ft_mall_check(tmp = ft_strdup(""));
	fd = open(filename, O_RDONLY);
	while (ft_gnl_check(get_next_line(fd, &str)) == 1)
		if (!ft_read_gnl(str, &tmp, &letter, all_lists))
			return (0);
	if (ft_strlen(tmp) != 0)
	{
		if (ft_strlen(tmp) != 20)
		{
			ft_strdel(&tmp);
			return (0);
		}
		ft_lst_back(all_lists, letter, tmp, ft_define_coordinates(tmp));
	}
	if (*tmp == '\0' || ft_check_last_ch(fd, filename) == 0)
		return (0);
	return (1);
}

void	ft_clear_map(char **map, char letter)
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
			if (map[i][j] == letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_find_in_array(const int ar[20], int what)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ar[i] == what)
			return (1);
		i++;
	}
	return (0);
}
