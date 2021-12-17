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
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*end;
	char	*line;
	int		size;
	static	char	*save_position;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		free(buffer);
		return (NULL);
	}
	end = buffer;
	while (*end && *end != '\n')
		end++;
	if (*(end + 1))
		save_position = end + 1;
	size = end - buffer + 1;
	if (*end == '\n')
		size += 1;
	line = malloc(sizeof(char) * size);
	ft_strlcpy(line, save_position, size);
	free(buffer);
	return (line);
}

int	main(int ac, char **av)
{
	(void)ac;
	int fd = open(*(av + 1), O_RDONLY);
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
