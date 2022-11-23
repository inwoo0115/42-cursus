/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:44:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/24 01:50:43 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *save_line)
{
	int	i;

	i = 0;
	while (save_line[i])
	{
		if (save_line[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*make_line(char	*save_line, int index)
{
}

char	*get_next_line(int fd)
{
	static char	*save_line[_SC_OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			index;
	int			read_size;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (0);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		save_line[fd] = ft_strjoin(save_line[fd], buff);
		index = check_newline(save_line[fd]);
		if (index)
			return (make_line(save_line[fd], index));
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	return (0);
}
