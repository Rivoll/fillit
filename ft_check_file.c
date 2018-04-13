/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <pkeita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:17:36 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/22 05:42:25 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_cube(char *str)
{
	int		i;
	int		j;

	if (ft_check_n_symbol(str) == -1)
		return (-1);
	j = 0;
	while (j != 4)
	{
		i = 0;
		while (*str && i != 4)
		{
			if (*str != '#' && *str != '.')
				return (-1);
			str++;
			i++;
		}
		if (*str != '\n')
			return (-1);
		str++;
		j++;
	}
	if (*str != '\n' && *str)
		return (-1);
	return (1);
}

int			ft_check_n_symbol(char *str)
{
	int		count_blocs;
	int		count_void;
	int		count_n;
	int		i;

	count_blocs = 0;
	count_void = 0;
	count_n = 0;
	i = 0;
	while (str[i] && i < 20)
	{
		if (str[i] == '#')
			count_blocs++;
		else if (str[i] == '.')
			count_void++;
		else if (str[i] == '\n')
			count_n++;
		else
			return (-1);
		i++;
	}
	if (count_blocs != 4 || count_void != 12 || count_n != 4)
		return (-1);
	return (1);
}

int			ft_check_file(char **str)
{
	char	**save_str;
	short	i;

	i = 0;
	save_str = str;
	while (str[i])
	{
		if ((ft_check_cube(str[i]) + ft_check_lien(str[i])) != 2)
			return (-1);
		if (!str[i + 1])
			return (str[i][20] == '\0') ? 1 : -1;
		else
			i++;
	}
	str = save_str;
	return (-1);
}

int			ft_check_lien(char *str)
{
	int		i;
	int		nb_lien;

	i = 0;
	nb_lien = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				nb_lien++;
			if (str[i - 1] == '#')
				nb_lien++;
			if (str[i - 5] == '#')
				nb_lien++;
			if (str[i + 5] == '#')
				nb_lien++;
		}
		i++;
	}
	if (nb_lien != 6 && nb_lien != 8)
		return (-1);
	return (1);
}
