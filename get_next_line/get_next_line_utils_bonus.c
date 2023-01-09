/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:16:27 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/09 12:34:41 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(int fd, char data[][BUFFER_SIZE + 1])
{
	char		*s2;
	int			i;

	if (fd < 0)
		return (0);
	s2 = (char *)malloc(ft_strlen(data[fd]) + 1);
	if (!(s2))
		return (0);
	i = 0;
	while (data[fd][i])
	{
		s2[i] = data[fd][i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
