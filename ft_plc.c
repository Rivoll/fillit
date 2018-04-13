/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:19:39 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/27 16:35:12 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map(int longueur)
{
	char*map;
	int	i;
	int	j;

	j = 0;
	map = (char*)malloc(sizeof(char) * (((longueur + 1) * longueur) + 1));
	while (j < longueur)
	{
		i = 0;
		while (i < longueur)
			map[i++] = '.';
		map[i++] = '\n';
		map += i;
		j++;
	}
	*map = '\0';
	map -= (longueur * i);
	return (map);
}

int		ft_plc(char **map, t_lstetri *tetri, int length_line, int decaleur)
{
	int	pos_a;
	int	pos_b;
	int	pos_c;
	int	pos_d;

	if (tetri->placed == 1)
		decaleur = ft_erase_tetriminos(map, tetri, length_line, 0) + 1;
	while (1)
	{
		pos_a = tetri->a.y * (1 + length_line) + tetri->a.x + decaleur;
		pos_b = tetri->b.y * (1 + length_line) + tetri->b.x + decaleur;
		pos_c = tetri->c.y * (1 + length_line) + tetri->c.x + decaleur;
		pos_d = tetri->d.y * (1 + length_line) + tetri->d.x + decaleur++;
		if (map[0][pos_d] == '\0')
			return (-1);
		if (map[0][pos_a] == '.' && map[0][pos_b] == '.' && map[0][pos_c] == '.'
			&& map[0][pos_d] == '.')
		{
			map[0][pos_a] = tetri->lettre;
			map[0][pos_b] = tetri->lettre;
			map[0][pos_c] = tetri->lettre;
			map[0][pos_d] = tetri->lettre;
			return (1);
		}
	}
}

int		ft_erase_tetriminos(char **map, t_lstetri *tetri, int length_line,
		int nb_decal)
{
	int	pos_a;
	int	pos_b;
	int	pos_c;
	int	pos_d;

	while (1)
	{
		pos_a = tetri->a.y * (1 + length_line) + tetri->a.x + nb_decal;
		pos_b = tetri->b.y * (1 + length_line) + tetri->b.x + nb_decal;
		pos_c = tetri->c.y * (1 + length_line) + tetri->c.x + nb_decal;
		pos_d = tetri->d.y * (1 + length_line) + tetri->d.x + nb_decal++;
		if (map[0][pos_d] == '\0')
			return (-1);
		if (map[0][pos_a] == tetri->lettre && map[0][pos_b] == tetri->lettre &&
			map[0][pos_c] == tetri->lettre && map[0][pos_d] == tetri->lettre)
		{
			map[0][pos_a] = '.';
			map[0][pos_b] = '.';
			map[0][pos_c] = '.';
			map[0][pos_d] = '.';
			tetri->placed = -1;
			return (nb_decal - 1);
		}
	}
}
