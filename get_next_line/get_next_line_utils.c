/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:38:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/17 21:47:28 by wonjilee         ###   ########.fr       */
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

char	*make_line(char *str, t_line newstr, int index, int j)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(ft_strlen(str) - index + ft_strlen(newstr.buff) + 1);
	if (new == 0)
		return (0);
	while (str[index])
		new[j++] = str[index++];
	while (newstr.buff[i])
		new[j++] = newstr.buff[i++];
	i = 0;
	while (new[i] && new[i] != '\n')
	{
		i++;
		if (new[i] == '\n')
		{
			newstr.save = new;
			newstr.index = i;
			break ;
		}
	}
	return (new);
}
