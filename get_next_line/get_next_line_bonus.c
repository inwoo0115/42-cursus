/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:13:16 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/09 13:16:37 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

char	*make_line(char *str, char *data, int i, int j)
{
	char	*new;

	new = (char *)malloc(next_line(str) + 2);
	if (new == 0)
		return (free_res(str, data));
	while (str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = '\n';
	new[i] = '\0';
	while (str[i])
	{
		data[j] = str[i];
		j++;
		i++;
	}
	data[j] = '\0';
	free(str);
	return (new);
}

char	*free_res(char *str, char *data)
{
	data[0] = '\0';
	if (str)
		free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	data[OPEN_MAX][BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*str;
	int			len;

	str = ft_strdup(fd, data);
	if (fd < 0 || read(fd, buff, 0) < 0 || str == 0)
		return (free_res(str, data[fd]));
	if (next_line(str) >= 0)
		return (make_line(str, data[fd], 0, 0));
	len = read(fd, buff, BUFFER_SIZE);
	while (len > 0)
	{
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
		if (str == 0)
			return (free_res(str, data[fd]));
		if (next_line(str) >= 0)
			return (make_line(str, data[fd], 0, 0));
		len = read(fd, buff, BUFFER_SIZE);
	}
	if (!(ft_strlen(str)))
		return (free_res(str, data[fd]));
	data[fd][0] = '\0';
	return (str);
}
