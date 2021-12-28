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

//tester read return value//
char	*get_next_line(int fd)
{
	size_t			size;
	char			*line;
	static char		*buf[BUFFER_SIZE + 1];

	if (fd == -1 || BUFFER_SIZE == 0 || read(fd, buf, BUFFER_SIZE) <= 0)
		return (NULL);
	size = 0;
	while (*buf[size] && *buf[size] != '\n')
		size++;
	if (*buf[size] == '\n')
		size += 1;
	line = ft_strndup(*buf, size);
	if (*buf[size])
		*buf = *buf + size;
	return (line);
}



/*char	*get_next_line(int fd)
{
	int				size;
	char			*end;
	char			*line;
	static char		start[BUFFER_SIZE + 1];
	static	char	*save_position;

	if (read(fd, start, BUFFER_SIZE) <= 0)
		return (NULL);
	end = start;
	printf("s:%c\n", *start);
	while (*end && *end != '\n')
		end++;
	if (*(end + 1))
		save_position = end + 1;
	printf("s_p:%c", *save_position);
	size = (end - start) + 1;
	if (*end == '\n')
		size += 1;
	line = malloc(sizeof(char) * size);
	ft_strlcpy(line, start, size);
	return (line);
	//return un strnjoin ici //
}
*/
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
	res = get_next_line(fd);
	print_s(res);
	close(fd);
	return (0);
}
