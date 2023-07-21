/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:40 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:41 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_letter(char *line, int i, t_state *stat)
{
	stat->str[stat->index] = line[i];
	stat->index++;
	stat->str[stat->index] = '\0';
}
