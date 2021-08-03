/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:31:33 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/03 15:31:33 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_cache	cache;
	ssize_t			maxcpy;
	char			*ret;

	ret = 0;
	while (1)
	{
		if (cache.offset >= cache.size)
		{
			cache.offset = 0;
			cache.size = read(fd, cache.buffer, BUFFER_SIZE);
			if (cache.size <= 0)
				return (ret);
		}
		maxcpy = ft_strichr(cache.buffer + cache.offset, '\n') + 1;
		ret = ft_strappend(ret, cache.buffer + cache.offset, maxcpy);
		cache.offset += maxcpy;
		if (ret == NULL)
			return (NULL);
		if (cache.offset <= cache.size)
			return (ret);
	}
}
