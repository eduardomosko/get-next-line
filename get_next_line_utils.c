/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:05:11 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/03 17:05:11 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strichr(const char *s, char target)
{
	size_t	i;

	i = 0;
	while (*s != '\0' && *s != target)
	{
		i++;
		s++;
	}
	return (i);
}

static size_t	ft_strlen_max(const char *s, size_t max)
{
	const char	*it;
	const char	*end;

	it = s;
	end = s + max;
	while (*s != '\0' && s != end)
		s++;
	return (it - s);
}

static char	*ft_strncpy(char *dest, const char *src, size_t max)
{
	const char	*end;

	end = src + max;
	while (*src != '\0' && src != end)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strappend(char *dest, const char *src, size_t maxcpy)
{
	size_t	size;
	char	*ret;
	char	*offset;

	size = ft_strlen_max(dest, -1);
	size += ft_strlen_max(src, maxcpy);
	ret = malloc(size + 1);
	if (ret == NULL)
	{
		free(dest);
		return (NULL);
	}
	offset = ft_strncpy(ret, dest, -1);
	ft_strncpy(offset, src, maxcpy);
	free(dest);
	return (ret);
}
