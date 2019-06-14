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

int		ft_validate_sharps(int i, int *connect, int *iconnect,
		const char *tetra)
{
	int isharp;

	isharp = 0;
	if (i - 5 >= 0 && tetra[i - 5] == '#' && ++isharp)
		if (!ft_find_in_array(connect, i + (i - 5)))
			connect[++*iconnect - 1] = i + (i - 5);
	if (i - 1 >= 0 && tetra[i - 1] == '#' && ++isharp)
		if (!ft_find_in_array(connect, i + (i - 1)))
			connect[++*iconnect - 1] = i + (i - 1);
	if (i + 5 <= 19 && tetra[i + 5] == '#' && ++isharp)
		if (!ft_find_in_array(connect, i + (i + 5)))
			connect[++*iconnect - 1] = i + (i + 5);
	if (i + 1 <= 19 && tetra[i + 1] == '#' && ++isharp)
		if (!ft_find_in_array(connect, i + (i + 1)))
			connect[++*iconnect - 1] = i + (i + 1);
	if (isharp == 0)
		return (0);
	else
		return (1);
}

void	ft_ar_init(int *p, int size)
{
	while (size--)
		p[size] = 0;
}

int		ft_validate_tet(const char *tetra)
{
	int count;
	int i;
	int connect[30];
	int iconnect;

	ft_ar_init(connect, 30);
	iconnect = 0;
	count = 0;
	i = 0;
	while (tetra[i])
	{
		if (tetra[i] != '#' && tetra[i] != '.' && tetra[i] != '\n')
			return (0);
		if (count > 4)
			return (0);
		if (tetra[i] == '#' && ++count)
			if (ft_validate_sharps(i, connect, &iconnect, tetra) == 0)
				return (0);
		i++;
	}
	if (iconnect > 2 && count == 4)
		return (1);
	return (0);
}

int		ft_validate_all_tetra(t_flist *tetra)
{
	while (tetra)
	{
		if (!ft_validate_tet(tetra->tetra))
			return (0);
		tetra = tetra->next;
	}
	return (1);
}

int		ft_check_insert(char **map, int i, int j, t_flist *tetra)
{
	int count;
	int iplus;
	int jplus;
	int size;

	size = ft_strlen(map[0]);
	count = 0;
	iplus = (ft_check_minus(tetra->tetra_i[count]) / 5) + i;
	jplus = (ft_mod(tetra->tetra_i[count] % 5)) + j;
	while (iplus < size && jplus < size && count < 4 &&
		jplus >= 0 && iplus >= 0 && map[iplus][jplus] == '.')
	{
		count++;
		iplus = (ft_check_minus(tetra->tetra_i[count]) / 5) + i;
		jplus = (ft_mod(tetra->tetra_i[count] % 5)) + j;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}
