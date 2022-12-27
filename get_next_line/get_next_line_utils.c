/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:38:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/27 23:13:08 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
		return (free_res(s1));
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}

int	check_read(int fd, t_line *data)
{
	if (fd < 0 || read(fd, data->buff, 0) < 0)
	{
		data->save[0] = '\0';
		data->buff[0] = '\0';
		return (1);
	}
	else
		return (0);
}

char	*ft_strdup(char *s1)
{
	char		*s2;
	int			i;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!(s2))
		return (free_res(s2));
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
