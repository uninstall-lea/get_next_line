#include <stdio.h>

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
	printf("%s", res);
	free(res);
	while (i < 100)
	{
		res = get_next_line(fd);
		printf("%s", res);
		free(res);
		i++;
	}
	close(fd);
	atexit(_leaks);
	return (0);
}