/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 06:04:25 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/27 17:01:47 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lstetri		*ft_add_tetri(t_lstetri *tetri, char lettre)
{
	t_lstetri	*tmp;
	t_lstetri	*first;

	first = tetri;
	while (tetri->next)
		tetri = tetri->next;
	tmp = (t_lstetri*)malloc(sizeof(t_lstetri));
	if (!tmp)
		return (NULL);
	tmp->placed = -1;
	tmp->lettre = lettre;
	tmp->next = tetri->next;
	tmp->prev = tetri;
	tetri->next = tmp;
	return (first);
}

t_lstetri		*ft_initialize_lstetri(void)
{
	t_lstetri	*tetriminos;

	tetriminos = (t_lstetri*)malloc(sizeof(t_lstetri));
	if (!tetriminos)
		return (NULL);
	tetriminos->lettre = 'A';
	tetriminos->placed = -1;
	tetriminos->prev = NULL;
	tetriminos->next = NULL;
	return (tetriminos);
}

t_lstetri		*ft_creat_lstetri(int i)
{
	int			j;
	char		lettre;
	t_lstetri	*tetriminos;

	tetriminos = ft_initialize_lstetri();
	j = 0;
	lettre = 'B';
	if (!tetriminos)
		return (NULL);
	while (j < i - 1)
	{
		tetriminos = ft_add_tetri(tetriminos, lettre++);
		j++;
	}
	return (tetriminos);
}

t_lstetri		*ft_modify_tetri(t_lstetri *tetriminos, char *str)
{
	int			i;
	int			refx;
	int			refy;

	i = 0;
	while (str[i] != '#')
		i++;
	refx = i % 5;
	refy = i / 5;
	tetriminos->a.x = 0;
	tetriminos->a.y = 0;
	while (str[i++] != '#')
		;
	tetriminos->b.x = ((i % 5) - refx);
	tetriminos->b.y = ((i / 5) - refy);
	while (str[i++] != '#')
		;
	tetriminos->c.x = ((i % 5) - refx);
	tetriminos->c.y = ((i / 5) - refy);
	while (str[i++] != '#')
		;
	tetriminos->d.x = ((i % 5) - refx);
	tetriminos->d.y = ((i / 5) - refy);
	return (tetriminos);
}

t_lstetri		*ft_stock_tetri_lst(char **str, int i)
{
	int			j;
	t_lstetri	*tetriminos;
	t_lstetri	*first;

	j = 0;
	tetriminos = ft_creat_lstetri(i);
	first = tetriminos;
	while (str[j])
	{
		ft_modify_tetri(tetriminos, str[j]);
		tetriminos = tetriminos->next;
		j++;
	}
	return (first);
}
