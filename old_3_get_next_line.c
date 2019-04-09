/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:11:38 by valecart          #+#    #+#             */
/*   Updated: 2019/04/09 19:28:16 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // delete this wtf

void		join_next_line(char **line, char **str, char **tmp)
{
	**tmp = '\0';
	*line = ft_strjoin(*line, *str);
	(*tmp)++;
	(*str) = (*tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				rd;
	char			buff[BUFF_SIZE];
	static char		*tmp;
	static char		*str;

	if (*line)
		ft_strdel(line);
	if ((tmp = ft_strchr(str, '\n')))
	{
		join_next_line(line, &str, &tmp);
		return (1);
	}
	rd = read(fd, buff, BUFF_SIZE);
	while (rd > 0)
	{
		str = ft_strjoin(str, buff);
		/*printf("\nSTR : >'%s'<\n", str);*/
		if ((tmp = ft_strchr(str, '\n')) != NULL)
		{
			join_next_line(line, &str, &tmp);
			return (1);
		}
		rd = read(fd, buff, BUFF_SIZE);
	}
	return (0);
}

int main(int ac, char **av)
{
	char *line;
	int fd;

	(void)ac;
	(void)av;
	int		call = 1;
#include <fcntl.h>
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%d appel: %s\n", call, line);
		call++;
	}
	return (0);
}
