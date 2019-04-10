/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:27:12 by valecart          #+#    #+#             */
/*   Updated: 2019/04/10 18:23:00 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static char	*join_next_line(int const fd, char *str, int *rd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	*rd = read(fd, buff, BUFF_SIZE);
	if (*rd < BUFF_SIZE && buff[*rd - 1] != '\n')
	{
		buff[*rd] = '\n';
		buff[*rd + 1] = '\0';
	}
	else
		buff[*rd] = '\0';
	tmp = str;
	str = ft_strjoin(str, buff);
	ft_strdel(&tmp);
	return (str);
}

#include <stdio.h>
int			get_next_line(int const fd, char **line)
{
	int				rd;
	char		*tmp;
	static char		*str = NULL;

	if (!line || fd < 0)
		return (-1);
	rd = 1;
	tmp = NULL;
	if (!str)
		str = ft_strnew(0);
	while (rd > 0)
	{
		if ((tmp = ft_strchr(str, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(str);
			tmp++;
			str = ft_memmove(str, tmp, ft_strlen(tmp) + 1);
			return (1);
		}
		str = join_next_line(fd, str, &rd);
	}
	if (ft_strlen(str) > 1 && (tmp = ft_strchr(str, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	if (rd == 0)
		*line = ft_strnew(0);
	return (rd);
}
