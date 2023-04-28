/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:14:37 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/28 17:15:35 by wonjilee         ###   ########.fr       */
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
