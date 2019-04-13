/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:27:12 by valecart          #+#    #+#             */
/*   Updated: 2019/04/13 13:25:13 by Valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static char		*join_next_line(int const fd, char *str, int *rd)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	*rd = read(fd, buff, BUFF_SIZE);
	if (*rd == -1)
		return (NULL);
	buff[*rd] = '\0';
	tmp = str;
	if (!(str = ft_strjoin(str, buff)))
	{
		if (str)
			ft_strdel(&str);
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_strdel(&tmp);
	return (str);
}

int				get_eof_line(char **str, char ***line)
{
	if ((ft_strlen(*str) > 1) && ft_strrchr(*str, '\0'))
	{
		if (!(**line = ft_strdup(*str)))
		{
			ft_strdel(str);
			return (-1);
		}
		ft_strdel(str);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				rd;
	char			*tmp;
	static char		*str = NULL;

	if (!line || fd < 0)
		return (-1);
	rd = 1;
	/*!str ? str = ft_strnew(0) : 0;*/
	if (!str)
		if (!(str = ft_strnew(0)))
			return (-1);
	while (rd > 0)
	{
		if ((tmp = ft_strchr(str, '\n')))
		{
			*tmp = '\0';
			if (!(*line = ft_strdup(str)))
			{
				ft_strdel(&str);
				return (-1);
			}
			tmp++;
			str = ft_memmove(str, tmp, ft_strlen(tmp) + 1);
			return (1);
		}
		if (!(str = join_next_line(fd, str, &rd)))
			return (-1);
	}
	if (get_eof_line(&str, &line) == 1)
		return (1);
	/*rd == 0 ? *line = ft_strnew(0) : 0;*/
	if (rd == 0)
	{
		if (!(*line = ft_strnew(0)))
		{
			if (str)
				ft_strdel(&str);
			return (-1);
		}
	}
	return (rd);
}
