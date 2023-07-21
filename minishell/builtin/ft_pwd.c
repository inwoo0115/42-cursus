/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:56 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:56 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_main *main)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		main->status = 1;
		ft_error2(PWD_ERROR, "pwd");
		return ;
	}
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
	main->status = 0;
	free(path);
}
