/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:23:51 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/09 14:26:45 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int				rd;
	static char		buff[BUFF_SIZE];
	static char			*tmp;

	if (tmp)
	{
		if (*line)
			free(*line);
		*line = ft_strjoin(*line, tmp);
	}
	if (!tmp)
		rd = read(fd, buff, BUFF_SIZE);
	else
		rd = 1;
	while (rd > 0)
	{
		/*if ((tmp = ft_strchr(*line, '\n')) != NULL)*/
		/*{*/
			/**tmp = '\0';*/
			/*tmp++;*/
			/*get_next_line(fd, line);*/
			/*return (1);*/
		/*}*/
		if ((tmp = ft_strchr(buff, '\n')) != NULL)
		{
			*tmp = '\0';
			tmp++;
			*line = ft_strjoin(*line, buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
		rd = read(fd, buff, BUFF_SIZE);
	}
	/*if (rd > 0)*/
		/*return (1);*/
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
