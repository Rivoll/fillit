/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkeita <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:26:00 by pkeita            #+#    #+#             */
/*   Updated: 2016/12/22 20:26:46 by pkeita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_read_st(char *file)
{
	int		ret;
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	**tab_char;
	int		i;

	i = 0;
	tab_char = (char**)malloc(sizeof(char*) * 27);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0 && i < 26)
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		tab_char[i++] = ft_strdup((const char*)buf);
	}
	while (i < 27)
		tab_char[i++] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (tab_char);
}
