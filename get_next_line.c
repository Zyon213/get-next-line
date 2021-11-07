/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:27:54 by yoyohann          #+#    #+#             */
/*   Updated: 2021/11/01 13:40:18 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_buff(int fd, char *str_line)
{
	char	*buff;
	int		s_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	s_bytes = 1;
	while (!ft_strchr(str_line, '\n') && s_bytes != 0)
	{
		s_bytes = read(fd, buff, BUFFER_SIZE);
		if (s_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[s_bytes] = '\0';
		str_line = ft_strjoin(str_line, buff);
	}
	free(buff);
	return (str_line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_line = ft_read_buff(fd, str_line);
	if (!str_line)
		return (NULL);
	line = ft_read_line(str_line);
	str_line = ft_extra_line(str_line);
	return (line);
}
