/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 23:07:26 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/22 21:50:57 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 21

typedef struct			s_bloc
{
	int					x;
	int					y;
}						t_bloc;

typedef struct			s_lstetri
{
	char				lettre;
	int					placed;
	t_bloc				a;
	t_bloc				b;
	t_bloc				c;
	t_bloc				d;
	struct s_lstetri	*prev;
	struct s_lstetri	*next;
}						t_lstetri;

int						ft_check_cube(char *str);

char					**ft_read_st(char *file);

int						ft_check_n_symbol(char *str);

int						ft_check_file(char **str);

int						*ft_list_tetriminos(char *str);

char					*ft_map(int longueur);

void					ft_print_lstetri(t_lstetri *tetriminos);

t_lstetri				*ft_check_lsttetri(t_lstetri *tetri);

int						ft_plc(char **map, t_lstetri *tetri, int length_line,
		int decaleur);

t_lstetri				*ft_add_tetri(t_lstetri *tetri, char lettre);

t_lstetri				*ft_initialize_lstetri();

t_lstetri				*ft_creat_lstetri(int i);

char					**ft_read_st(char *file);

t_lstetri				*ft_modify_tetri(t_lstetri *tetriminos, char *str);

t_lstetri				*ft_stock_tetri_lst(char **str, int i);

int						ft_check_placed(t_lstetri *tetri);

int						ft_check_lien(char *str);

int						ft_erase_tetriminos(char **map,
	t_lstetri *tetri, int length_line, int nb_decal);

void					ft_resolve_it(t_lstetri *tetri,
	char **map, int length_line);

void					ft_putstr(const char *str);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
void					ft_putchar(char str);
#endif
