/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbisson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:07:20 by lbisson           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:42 by lbisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *start)
{
	const char	*end;

	end = start;
	while (*end)
		end++;
	return (end - start);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
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
	new_str = ft_strncpy(new_str, src, n + 1);
	new_str[n] = '\0';
	return (new_str);
}
