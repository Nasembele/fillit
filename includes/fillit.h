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

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_flist {
	int				*tetra_i;
	char			letter;
	char			*tetra;
	int				ipos;
	int				jpos;
	struct s_flist	*next;
}					t_flist;

int					ft_gnl_check(int gnl);
void				ft_mall_check(void *ptr);
void				ft_print_map(char **map);
void				ft_free_map(char ***map);
void				ft_generate_map(char ***map, int size);
int					ft_mod(int num);
int					ft_check_minus(int num);
void				ft_handle_coordinates_up(t_flist *tetra);
void				ft_handle_coordinates(t_flist *tetra);
void				ft_lst_back(t_flist **all_list, char letter,
		char *tetra, int *tetra_index);
int					*ft_define_coordinates(const char *tetra);
int					ft_read_gnl(char *str, char **tmp, char *letter,
		t_flist **all_lists);
int					ft_read_tet(t_flist **all_lists, char *filename);
void				ft_clear_map(char **map, char letter);
int					ft_find_in_array(const int ar[20], int what);
int					ft_validate_sharps(int i, int *connect,
		int *iconnect, const char *tetra);
void				ft_ar_init(int *p, int size);
int					ft_validate_tet(const char *tetra);
int					ft_validate_all_tetra(t_flist *tetra);
int					ft_check_insert(char **map, int i, int j, t_flist *tetra);
void				ft_insert_tet(char **map, int i, int j, t_flist *tetra);
int					ft_insert_where(char **map, int size, t_flist *tetra);
int					ft_algo(char ***map, size_t size, t_flist *tetra);
void				ft_lst_del_all(t_flist **all_list);
int					ft_check_last_ch(int fd, char *filename);

#endif
