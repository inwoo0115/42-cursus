/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:36 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:36 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error1(int code)
{
	if (code == QOUTE_ERROR)
		ft_error_printf("minishell: qoute error\n");
	else if (code == ENV_ERROR)
		ft_error_printf("minishell: too many arguments\n");
	else if (code == PWD_ERROR)
		ft_error_printf("minishell: can't get pwd error\n");
	else if (code == EXIT_MANY_ARG_ERROR)
		ft_error_printf("minishell: exit: too many arguments\n");
	else if (code == NOT_SET_HOME_ERROR)
		ft_error_printf("minishell: cd: HOME not set\n");
	else if (code == NOT_SET_OLDPWD_ERROR)
		ft_error_printf("minishell: cd: OLDPWD not set\n");
	else if (code == OPEN_ERROR)
		ft_error_printf("minishell: Open error\n");
}

void	ft_error2(int code, char *str)
{
	if (code == UNSET_ERROR)
		ft_error_printf("minishell: unset: `%s': not a valid identifier\n", str);
	else if (code == EXIT_NOT_DIGIT_ERROR)
		ft_error_printf("minishell: exit: %s: numeric argument required\n", str);
	else if (code == EXPORT_ERROR)
		ft_error_printf(\
		"minishell: export: `%s': not a valid identifier\n", str);
	else if (code == CD_NO_PATH_ERROR)
		ft_error_printf("minishell: cd: %s: No such file or directory\n", str);
	else if (code == PERMISSION_ERROR)
		ft_error_printf("minishell: %s: Permission denied\n", str);
	else if (code == IN_NOFILE_ERROR)
		ft_error_printf("minishell: %s: No such file or directory\n", str);
	else if (code == NO_EXIST_CMD_ERROR)
		ft_error_printf("minishell: %s: command not found\n", str);
	else if (code == NOT_LL_ERROR)
		ft_error_printf("minishell: exit: %s: numeric argument required\n", str);
	else if (code == IS_A_DIRECTORY)
		ft_error_printf("minishell: %s: is a directory\n", str);
	else if (code == NOT_A_DIRECTORY)
		ft_error_printf("minishell: %s: Not a directory\n", str);
}

int	check_tok(char *line, int i, char c)
{
	if (i + 1 < (int)ft_strlen(line) && line[i + 1] == c)
		return (1);
	return (0);
}

void	syntax_error(t_main *main, char *line, int i, t_state *stat)
{
	char	tok[3];

	tok[0] = line[i];
	tok[1] = '\0';
	tok[2] = '\0';
	if (check_tok(line, i, line[i]))
		tok[1] = line[i];
	ft_error_printf("minishell: syntax error near unexpected token `%s'\n", tok);
	main->status = 258;
	main->cmd_num = -1;
	stat->syn_error = 1;
}

void	syntax_error_null(t_main *main, t_state *stat)
{
	ft_error_printf("minishell: syntax error near unexpected token `newline'\n");
	main->status = 258;
	main->cmd_num = -1;
	stat->syn_error = 1;
}
