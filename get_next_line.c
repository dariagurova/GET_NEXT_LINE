/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:52:01 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/27 19:02:59 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char	*str_realloc(char *old, size_t size)
{
	char *new;

	if (!old)
	{
		new = ft_strnew(size);
		return (new);
	}
	new = ft_strnew(ft_strlen(old) + size);
	ft_strcpy(new, old);
	ft_strdel(&old);
	return (new);
}

int		fillout(char **line, char *buffer)
{
	char	*tmp;
	int		len;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*line = str_realloc(*line, tmp - buffer);
		ft_strncat(*line, buffer, tmp - buffer);
		ft_memmove(buffer, tmp + 1, ft_strlen(tmp));
		return (1);
	}
	if ((len = ft_strlen(buffer)))
	{
		*line = str_realloc(*line, len);
		ft_strncat(*line, buffer, len);
		*buffer = '\0';
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buff[FD_MAX];
	int			bytes;

	if (fd < 0 || fd >= FD_MAX || !line || BUFF_SIZE < 1)
		return (-1);
	else if (!buff[fd] && !(buff[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;
	if (fillout(line, buff[fd]))
		return (1);
	while ((bytes = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][bytes] = '\0';
		if (fillout(line, buff[fd]))
			return (1);
	}
	if (*line)
		return (1);
	ft_strdel(&buff[fd]);
	if (bytes < 0)
		return (-1);
	return (0);
}
