/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:52:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:05 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_line(void)
{
	ft_printf_str("\033[1A");
	ft_printf_str("\033[10C");
	ft_printf_str(" exit\n");
	exit(0);
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_printf_str("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 1;
	}
}

void	set_terminal(void)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	termios.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, 0, &termios);
}

void	set_signal(void)
{
	set_terminal();
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_handler);
}
