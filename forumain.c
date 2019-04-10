#include "get_next_line.h"
#include <stdio.h>
int main(int ac, char **av)
{
	char *line;
	int fd;

	(void)ac;
	(void)av;
	int		call = 1;
#include <fcntl.h>
	fd = open(av[1], O_RDONLY);
	int		ret;
	/*get_next_line(fd, &line);*/
	/*printf("%d\n", ft_strcmp(line, "abcdefghijklmnop"));*/
	/*get_next_line(fd, &line);*/
	/*printf("%d\n", ft_strcmp(line, "qrstuvwxyzabcdef"));*/
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		/*printf("%d appel: %s\n, ", call, line);*/
		printf("[%d]%s\n", call, line);
		call++;
	}
		/*printf("\nret: %d, line: %s\n", ret, line);*/
	return (0);
}
