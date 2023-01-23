/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:47:32 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/24 05:28:25 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_line(char	*str, t_list *data, t_list **head, int fd)
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
		return (free_res(data, head, fd));
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

t_list	*check_data(t_list **head, int fd)
{
	t_list	*new;
	t_list	*curr;

	if (*head == NULL)
	{
		*head = malloc(sizeof(t_list));
		if (*head == NULL)
			return (0);
		create_data(*head, fd);
	}
	curr = *head;
	while (curr->next && curr->fd != fd)
		curr = curr->next;
	if (fd == curr->fd)
		return (curr);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	create_data(new, fd);
	curr->next = new;
	return (new);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_newline(char *str, t_list *data, int i, int j)
{
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\n')
		return (0);
	data->index = i;
	i++;
	while (str[i])
		data->buff[j++] = str[i++];
	data->len = i - data->index;
	data->buff[j] = '\0';
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len;
	char		*newstr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(len + 1);
	if (newstr == 0)
	{
		free(s1);
		return (0);
	}
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
