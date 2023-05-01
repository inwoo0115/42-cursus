/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:37 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/01 16:28:28 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

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

char	*ft_strjoin_gnl(char *s1, char *s2)
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
