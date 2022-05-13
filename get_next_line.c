/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:44:11 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/10 13:58:14 by lbisson          ###   ########.fr       */
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
static void	handle_end_of_file(int fd, int *start, int *size, char *buf)
{
	if (!buf[*size])
		handle_end_of_buf(fd, start, size, buf);
	return ;
}

static char	*read_and_fill(int fd, char *buf)
{
	char		*line;
	int			start;
	static int	size = 0;

	line = NULL;
	start = size;
	if (size == BUFFER_SIZE)
		handle_end_of_buf(fd, &start, &size, buf);
	while (buf[size] && buf[size] != '\n')
	{
		if (size == BUFFER_SIZE - 1)
		{
			line = ft_strnjoin_gnl(line, &buf[start], BUFFER_SIZE - start);
			if (!line)
				return (NULL);
			if (handle_end_of_buf(fd, &start, &size, buf) <= 0)
				return (line);
		}
		else
			size++;
	}
	line = ft_strnjoin_gnl(line, &buf[start], ++size - start);
	handle_end_of_file(fd, start, size, buf);
	if (line && line[0] == '\0')
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf[0] && read(fd, buf, BUFFER_SIZE) <= 0)
		return (NULL);
	return (read_and_fill(fd, buf));
}
