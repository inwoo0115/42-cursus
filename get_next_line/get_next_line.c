/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:11:57 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/17 22:12:11 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_newline(int fd, char *buff, char *data, int len)
{
	char	*temp;

	len = read(fd, buff, BUFFER_SIZE);
	if (len < 0)
		return (0);
	while (len > 0)
	{
		buff[len] = '\0';
		if (!data)
		{
			data = (char *)malloc(1);
			if (!(data))
				return (0);
			data[0] = '\0';
		}
		temp = data;
		data = ft_strjoin(temp, buff);
		free(temp);
		if (!(data))
			return (0);
		if (check_newline(data))
			break ;
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (data);
}

char	*make_data(char *str)
{
	char	*temp;
	int		i;
	int		j;
	int		index;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	index = i;
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (0);
	temp = (char *)malloc(ft_strlen(str) - i);
	if (!temp)
		return (0);
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	str[index + 1] = '\0';
	return (temp);
}

char	*make_line(char	*str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(ft_strlen(str) + 1);
	if (!temp)
	{
		free(str);
		str = 0;
		return (0);
	}
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	free(str);
	str = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*buff;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buff))
		return (0);
	str = get_newline(fd, buff, data, 1);
	free(buff);
	buff = 0;
	if (str == 0 || str[0] == '\0')
	{
		free(data);
		data = 0;
		return (0);
	}
	data = make_data(str);
	return (make_line(str));
}
