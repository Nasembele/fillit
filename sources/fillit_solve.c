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

void	ft_insert_tet(char **map, int i, int j, t_flist *tetra)
{
	int count;
	int iplus;
	int jplus;

	count = 0;
	iplus = (ft_check_minus(tetra->tetra_i[count]) / 5) + i;
	jplus = (ft_mod(tetra->tetra_i[count] % 5)) + j;
	while (count < 4 && map[iplus][jplus] == '.')
	{
		map[iplus][jplus] = tetra->letter;
		count++;
		iplus = (ft_check_minus(tetra->tetra_i[count]) / 5) + i;
		jplus = (ft_mod(tetra->tetra_i[count] % 5)) + j;
	}
}

int		ft_insert_where(char **map, int size, t_flist *tetra)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == '.' && (i * 10 + j) > (tetra->ipos * 10
				+ tetra->jpos) && ft_check_insert(map, i, j, tetra))
			{
				tetra->ipos = i;
				tetra->jpos = j;
				ft_insert_tet(map, i, j, tetra);
				return (1);
			}
			j++;
		}
		i++;
	}
	tetra->jpos = -1;
	tetra->ipos = -1;
	return (0);
}

int		ft_algo(char ***map, size_t size, t_flist *tetra)
{
	if (tetra == NULL)
		return (1);
	while (ft_insert_where(*map, size, tetra))
	{
		if (ft_algo(map, size, tetra->next))
			return (1);
		else
			ft_clear_map(*map, tetra->letter);
	}
	if (tetra->letter == 'A')
	{
		size++;
		ft_generate_map(map, size);
		if (ft_algo(map, size, tetra))
			return (1);
	}
	return (0);
}

void	ft_lst_del_all(t_flist **all_list)
{
	t_flist *list;
	t_flist *tmp;

	list = *all_list;
	while (list)
	{
		tmp = list->next;
		free(list->tetra_i);
		free(list->tetra);
		free(list);
		list = tmp;
	}
	*all_list = NULL;
}

int		ft_check_last_ch(int fd, char *filename)
{
	char buf[1];

	close(fd);
	fd = open(filename, O_RDONLY);
	while (read(fd, buf, 1))
		;
	if (buf[0] == '\n')
		return (1);
	return (0);
}
