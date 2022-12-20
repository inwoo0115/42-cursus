/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:44:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/21 00:01:19 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	next_line(char *str, t_line data)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		data.index = i;
		return (1);
	}
	else
	{
		data.index = -1;
		return (0);
	}
}

char	*make_line(char *str, t_line data)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(data.index + 2);
	if (new == 0)
		return (0);
	while (i <= data.index)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	while (str[i])
	{
		data.save[j] = str[i];
		j++;
		i++;
	}
	data.save[j] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_line	data = {"\0", "\0", -1, 0};
	char			*str;

	if (fd < 0 || read(fd, data.buff, 0) < 0)
		return (0);
	str = data.save;
	if (data.index >= 0 && next_line(str, data) >= 0)
		return (make_line(str, data));
	data.len = read(fd, data.buff, BUFFER_SIZE);
	if (data.len <= 0)
		return (0);
	while (data.len > 0)
	{
		data.buff[data.len] = '\0';
		str = ft_strjoin(str, data.buff);
		if (str == 0)
			return (0);
		if (next_line(str, data) >= 0)
			return (make_line(str, data));
		data.len = read(fd, data.buff, BUFFER_SIZE);
	}
	return (str);
}

#include <fcntl.h>


int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	printf("%s\n", str);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}