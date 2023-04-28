/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/28 23:51:53 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

char	*find_data(t_list *data, int i)
{
	char	*temp;

	if (data->index == -1)
	{
		temp = (char *)malloc(1);
		if (!temp)
			return (0);
		temp[0] = '\0';
	}
	else
	{
		temp = (char *)malloc(data->len);
		if (!temp)
			return (0);
		while (i < data->len - 1)
		{
			temp[i] = data->buff[i];
			i++;
		}
		temp[i] = '\0';
		data->index = -1;
		data->len = 0;
		data->buff[0] = '\0';
	}
	return (temp);
}

char	*get_newline(int fd, char *buff, t_list *data, int len)
{
	char	*temp;

	temp = find_data(data, 0);
	if (!temp)
		return (0);
	if (check_newline(temp, data, 0, 0))
		return (temp);
	len = read(fd, buff, BUFFER_SIZE);
	if (len < 0)
	{
		free(temp);
		return (0);
	}
	while (len > 0)
	{
		buff[len] = '\0';
		temp = ft_strjoin_gnl(temp, buff);
		if (!temp)
			return (0);
		if (check_newline(buff, data, 0, 0))
			break ;
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (temp);
}

char	*make_line(char	*str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
		return (str);
	i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
	{
		free(str);
		return (0);
	}
	while (j < i)
	{
		temp[j] = str[j];
		j++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	data = {0, -1, 0, "\0"};
	char			*buff;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buff))
		return (0);
	str = get_newline(fd, buff, &data, 1);
	free(buff);
	buff = 0;
	if (str == 0 || str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (make_line(str));
}
