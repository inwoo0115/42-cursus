/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:38:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/20 23:50:47 by wonjilee         ###   ########.fr       */
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
		return (0);
	while (s1[j])
		newstr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	if (ft_strlen(s1))
		free(s1);
	return (newstr);
}
