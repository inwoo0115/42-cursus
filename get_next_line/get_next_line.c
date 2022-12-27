/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:44:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/27 21:08:59 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_line(char *str, t_line *data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		data->index = i;
		return (1);
	}
	else
	{
		data->index = -1;
		return (0);
	}
}

char	*make_line(char *str, char *buff, t_line *data)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(data->index + 2);
	if (new == 0)
		return (0);
	while (i <= data->index)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	while (str[i])
	{
		data->save[j] = str[i];
		j++;
		i++;
	}
	data->save[j] = '\0';
	free(str);
	free(buff);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_line	data = {"\0", -1, 0};
	char			*str;
	char			*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || read(fd, buff, 0) < 0)
	{
		free(buff);
		return (0);
	}
	str = ft_strdup(data.save);
	if (next_line(str, &data))
		return (make_line(str, buff, &data));
	data.len = read(fd, buff, BUFFER_SIZE);
	if (data.len <= 0)
	{
		free(buff);
		if (ft_strlen(str))
			return (str);
		else
			free(str);
		return (0);
	}
	buff[data.len] = '\0';
	while (data.len > 0)
	{
		str = ft_strjoin(str, buff);
		if (str == 0)
		{
			free(str);
			free(buff);
			return (0);
		}
		if (next_line(str, &data))
			return (make_line(str, buff, &data));
		data.len = read(fd, buff, BUFFER_SIZE);
		buff[data.len] = '\0';
	}
	free(buff);
	return (str);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/