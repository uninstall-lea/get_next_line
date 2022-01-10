/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:44:11 by lbisson           #+#    #+#             */
/*   Updated: 2022/01/10 15:57:44 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	handle_end_of_buf(int fd, int *start, int *size, char *buf)
{
	ft_memset(buf, '\0', BUFFER_SIZE);
	*size = 0;
	*start = 0;
	return (read(fd, buf, BUFFER_SIZE));
}

static char	*read_and_fill(int fd, char *buf)
{
	char		*line;
	int			start;
	static int	size = 0;

	line = NULL;
	start = size;
	while (buf[size] && buf[size] != '\n')
	{
		if (size == BUFFER_SIZE - 1)
		{
			line = ft_strnjoin(line, &buf[start], BUFFER_SIZE - start);
			if (handle_end_of_buf(fd, &start, &size, buf) <= 0)
				return (line);
		}
		else
			size++;
	}
	size += 1;
	line = ft_strnjoin(line, &buf[start], size - start);
	if (size >= BUFFER_SIZE - 1)
		handle_end_of_buf(fd, &start, &size, buf);
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!buf[0] && read(fd, buf, BUFFER_SIZE) <= 0)
		return (NULL);
	return (read_and_fill(fd, buf));
}

void _leaks(void)
{
system("leaks a.out");
}

#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(*(av + 1), O_RDONLY);
	char *res = get_next_line(fd);
	int i = 0;
	printf("%s", res);
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

