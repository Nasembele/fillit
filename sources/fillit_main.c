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

int		main(int argc, char **argv)
{
	t_flist		*all_tetra;
	char		**map;

	if (argc == 2)
	{
		map = NULL;
		all_tetra = NULL;
		if (!ft_read_tet(&all_tetra, argv[1]) ||
			!ft_validate_all_tetra(all_tetra))
		{
			ft_lst_del_all(&all_tetra);
			ft_putstr("error\n");
			return (0);
		}
		ft_generate_map(&map, 2);
		if (!ft_algo(&map, 2, all_tetra))
			return (0);
		ft_print_map(map);
		ft_free_map(&map);
		ft_lst_del_all(&all_tetra);
	}
	else
		ft_putstr("usage: ./fillit file\n");
	return (0);
}
