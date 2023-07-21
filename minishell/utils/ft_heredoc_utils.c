/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:46 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:47 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cursor(void)
{
	ft_printf_str("\033[1A");
	ft_printf_str("\033[2C");
}

void	put_str(char *str, char *file, int i)
{
	while (file[++i])
		str[i] = file[i];
	str[i] = '\0';
}
