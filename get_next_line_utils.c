/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:07:20 by lbisson           #+#    #+#             */
/*   Updated: 2022/01/10 15:50:24 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *start)
{
	const char	*end;

	if (!start)
		return (0);
	end = start;
	while (*end)
		end++;
	return (end - start);
}

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *) ptr;
	while (i < n)
	{	
		dest[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * n + 1);
	if (!new_str)
		return (NULL);
	ft_strncpy(new_str, src, n);
	new_str[n] = '\0';
	return (new_str);
}

/* Version with s1 freed for gnl */
char	*ft_strnjoin_gnl(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (!s1)
		return (ft_strndup(s2, n));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (n > s2_len)
		n = s2_len;
	new_str = malloc(sizeof(char) * (s1_len + n + 1));
	if (!new_str)
		return (NULL);
	ft_strncpy(new_str, s1, s1_len);
	ft_strncpy(new_str + s1_len, s2, n);
	free(s1);
	new_str[s1_len + n] = '\0';
	return (new_str);
}
