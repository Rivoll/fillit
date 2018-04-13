/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:14:11 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/27 16:55:05 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_count_nb_tetri(char **str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				main(int ac, char **av)
{
	char		**str;
	int			nb_tetri;
	t_lstetri	*tetri;
	char		*map;
	int			size_map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		return (0);
	}
	str = ft_read_st(av[1]);
	if (!str || ft_check_file(str) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	nb_tetri = ft_count_nb_tetri(str);
	size_map = 2;
	tetri = ft_stock_tetri_lst(str, nb_tetri);
	map = ft_map(size_map);
	ft_resolve_it(tetri, &map, size_map);
	ft_putstr(map);
	return (0);
}

void			ft_resolve_it(t_lstetri *tetri, char **map, int length_line)
{
	while (tetri)
	{
		if (ft_plc(map, tetri, length_line, 0) == -1)
		{
			if (tetri->prev)
				tetri = tetri->prev;
			else
			{
				length_line++;
				map[0] = ft_map(length_line);
			}
		}
		else
		{
			tetri->placed = 1;
			tetri = tetri->next;
		}
	}
}
