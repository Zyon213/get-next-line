/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:27:54 by yoyohann          #+#    #+#             */
/*   Updated: 2021/11/01 13:19:54 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str_line, char *buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!str_line)
	{
		str_line = (char *)malloc(1 * sizeof(char));
		str_line[0] = '\0';
	}
	if (!str_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(str_line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str_line)
		while (str_line[++i] != '\0')
			str[i] = str_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(str_line) + ft_strlen(buff)] = '\0';
	free(str_line);
	return (str);
}

char	*ft_read_line(char *str_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!str_line[i])
		return (NULL);
	while (str_line[i] && str_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (str_line[i] && str_line[i] != '\n')
	{
		str[i] = str_line[i];
		i++;
	}
	if (str_line[i] == '\n')
	{
		str[i] = str_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_extra_line(char *str_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str_line[i] && str_line[i] != '\n')
		i++;
	if (!str_line[i])
	{
		free(str_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (str_line[i])
		str[j++] = str_line[i++];
	str[j] = '\0';
	free(str_line);
	return (str);
}
