/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:05:18 by yoyohann          #+#    #+#             */
/*   Updated: 2021/11/01 13:13:18 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_buff(int fd, char *str_line);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str_line, char *buff);
size_t	ft_strlen(char *s);
char	*ft_read_line(char *str_line);
char	*ft_extra_line(char *str_line);

#endif
