/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:47:07 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/24 05:28:22 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	create_data(t_list *data, int fd)
{
	data->fd = fd;
	data->index = -1;
	data->len = 0;
	data->buff[0] = '\0';
	data->next = 0;
}

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
		temp = ft_strjoin(temp, buff);
		if (!temp)
			return (0);
		if (check_newline(buff, data, 0, 0))
			break ;
		len = read(fd, buff, BUFFER_SIZE);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*data;
	char			*buff;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	data = check_data(&head, fd);
	if (!data)
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buff))
		return (free_res(data, &head, fd));
	str = get_newline(fd, buff, data, 1);
	free(buff);
	buff = 0;
	if (str == 0 || str[0] == '\0')
	{
		free(str);
		return (free_res(data, &head, fd));
	}
	return (make_line(str, data, &head, fd));
}

char	*free_res(t_list *data, t_list **head, int fd)
{
	t_list	*curr;

	curr = *head;
	while (curr->next && (curr->next)->fd != fd)
		curr = curr->next;
	if (curr->next && fd == curr->next->fd)
	{
		curr->next = data->next;
		free(data);
	}
	else if ((*head)->fd == fd)
	{
		if ((*head)->next == NULL)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
			*head = (*head)->next;
			free(data);
		}
	}
	return (0);
}
