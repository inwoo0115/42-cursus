/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:44:09 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/17 21:46:18 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_line	newstr = {"\0", "\0", -1, 0};
	char			*str;

	if (fd < 0 || read(fd, newstr.buff, 0) < 0)
		return (0);
	newstr.len = read(fd, newstr.buff, BUFFER_SIZE);
	str = newstr.save;
	while (newstr.len > 0)
	{
		newstr.buff[newstr.len] = '\0';
		str = make_line(str, newstr, newstr.index + 1, 0);
		if (str == 0)
			return (0);
		if (newstr.index >= 0)
		{
			str[newstr.index + 1] = '\0';
			return (str);
		}
		newstr.len = read(fd, newstr.buff, BUFFER_SIZE);
	}
	newstr.index = -1;
	return (str);
}
