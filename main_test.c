#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void _leaks(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(*(av + 1), O_RDONLY);
	char *res = get_next_line(fd);
	int i = 0;
	write(1, res, strlen(res) + 1);
	free(res);
	while (i < 100)
	{
		res = get_next_line(fd);
		if (res)
			write(1, res, strlen(res) + 1);
		else
			printf("(null)");
		free(res);
		i++;
	}
	close(fd);
	//atexit(_leaks);
	return (0);
}
