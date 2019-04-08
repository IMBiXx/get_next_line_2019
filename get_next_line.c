/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Valentin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:23:51 by Valentin          #+#    #+#             */
/*   Updated: 2019/04/08 23:07:01 by Valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	int		rd;
	char	buff[BUFF_SIZE];

	while (!ft_strchr(buff, '\n') && rd > 0)
	{
		rd = read(fd, buff, BUFF_SIZE);
		*line = ft_strjoin(*line, buff);
	}
	if (rd > 0)
		return (1);
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
