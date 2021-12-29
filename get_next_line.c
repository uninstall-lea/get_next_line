/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:44:11 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/17 03:27:28 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h> // à retirer

static char	*read_and_fill(int fd, char *buf)
{
	char			*line;
	static size_t	size = 0;

	line = NULL;
	while (buf[size] && buf[size] != '\n')
	{
		if (size == BUFFER_SIZE)
		{
			size = 0;
			line = ft_strnjoin(line, buf, BUFFER_SIZE);
			if (read(fd, buf, BUFFER_SIZE) < 0)
				return (NULL);
		}
		else
			size++;
	}
	line = ft_strnjoin(line, buf, size);
	return (line);
}

//tester read return value//
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!buf[0])
		read(fd, buf, BUFFER_SIZE);
	return (read_and_fill(fd, buf));
}

void	print_s(char *s)
{
	write(1, s, ft_strlen(s));
}

int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(*(av + 1), O_RDONLY);
	char *res = get_next_line(fd);
	print_s(res);
	free(res);
	res = get_next_line(fd);
	print_s(res);
	free(res);
	close(fd);
	return (0);
}
