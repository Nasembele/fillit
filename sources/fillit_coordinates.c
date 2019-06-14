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

int		ft_mod(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int		ft_check_minus(int num)
{
	if (num == -1)
		return (-(5));
	else if (num == -2)
		return (-(6));
	else if (num == -6)
		return (-(5) * 2);
	else
		return (num);
}

void	ft_handle_coordinates_up(t_flist *tetra)
{
	int count;

	count = 0;
	if (tetra->tetra_i[0] != 0)
		while (1)
		{
			if (tetra->tetra_i[count] - 5 < 0)
				if (tetra->tetra_i[count] == -1)
					tetra->tetra_i[count] = -6;
				else
					tetra->tetra_i[count] = tetra->tetra_i[count] * -1;
			else
				tetra->tetra_i[count] = tetra->tetra_i[count] - 5;
			count++;
			if (count == 4)
			{
				if (tetra->tetra_i[0] == 0 || tetra->tetra_i[1] == 0
					|| tetra->tetra_i[2] == 0 || tetra->tetra_i[3] == 0)
					break ;
				else
					count = 0;
			}
		}
}

void	ft_handle_coordinates(t_flist *tetra)
{
	int count;

	count = 0;
	if (tetra->tetra_i[0] % 5 != 0 && tetra->tetra_i[1] % 5 != 0
		&& tetra->tetra_i[2] % 5 != 0 && tetra->tetra_i[3] % 5 != 0)
		while (1)
		{
			tetra->tetra_i[count] = tetra->tetra_i[count] - 1;
			count++;
			if (count == 4)
			{
				if (tetra->tetra_i[0] % 5 == 0 || tetra->tetra_i[1] % 5 == 0
					|| tetra->tetra_i[2] % 5 == 0 || tetra->tetra_i[3] % 5 == 0)
					break ;
				else
					count = 0;
			}
		}
	ft_handle_coordinates_up(tetra);
}

void	ft_lst_back(t_flist **all_list, char letter,
					char *tetra, int *tetra_index)
{
	t_flist		*tmp;
	t_flist		*new_flist;

	tmp = *all_list;
	if (tmp != NULL)
		while (tmp->next)
			tmp = tmp->next;
	ft_mall_check(new_flist = (t_flist *)malloc(sizeof(t_flist)));
	new_flist->letter = letter;
	new_flist->tetra = tetra;
	new_flist->tetra_i = tetra_index;
	new_flist->next = NULL;
	new_flist->jpos = -1;
	new_flist->ipos = -1;
	ft_handle_coordinates(new_flist);
	if (*all_list != NULL)
		tmp->next = new_flist;
	else
		*all_list = new_flist;
}
