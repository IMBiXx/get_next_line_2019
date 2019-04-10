
//# include <fw.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <regex.h>
# include <assert.h>
int		main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefghijklmnop\n1", 17);
	write(fd, "qrstuvwxyzabcdef\n1", 17);
	close(p[1]);
	dup2(out, fd);
	ret = get_next_line(p[0], &line);
	printf("ret 1 (%d): %d, line: %s\n", ret, strcmp(line, "abcdefghijklmnop"), line);
	ret = get_next_line(p[0], &line);
	printf("ret 2 (%d): %d, line: %s\n", ret, strcmp(line, "qrstuvwxyzabcdef"), line);
	ret = get_next_line(p[0], &line);
	printf("ret 3 (%d)", ret);
	return (0);
}
