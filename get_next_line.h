/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emendes- <emendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:53:06 by emendes-          #+#    #+#             */
/*   Updated: 2021/08/03 15:53:06 by emendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_cache
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	size;
	ssize_t	offset;
}	t_cache;

size_t	ft_strichr(const char *s, char target);
char	*ft_strappend(char *dest, const char *src, size_t maxcpy);

char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
