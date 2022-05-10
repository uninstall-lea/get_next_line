/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:55:55 by lbisson           #+#    #+#             */
/*   Updated: 2022/05/10 14:08:51 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strnjoin_gnl(char *s1, const char *s2, size_t n);
void	*ft_memset(void *ptr, int c, size_t n);

#endif
