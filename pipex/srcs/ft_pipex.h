/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:44:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/02 21:33:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# define READ 0
# define WRITE 1

typedef struct s_data
{
	int		fds[2][2];
	int		status;
	int		inf_fd;
	int		outf_fd;
	int		cmd_num;
	int		exit_status;
	char	*infile;
	char	*outfile;
	char	**paths;
	char	**envp;
	char	**cmd;
}	t_data;

//main
int		free_res(t_data *data);
void	get_path(t_data *data, char **envp, int i);
void	init_data(t_data *data, int argc, char **argv, char **envp);

//run_cmd
void	run_cmd(t_data *data, char *cmd, int i);
int		ft_execve(t_data *data, char *path, char **cmds, char *cmd);

//pipex_split
char	**make_split(char const *s, char c, char **split_word);
int		num_word(char const *s, char c);
int		num_letter(char const *s, char c, int i);
char	**split_free(char **split_word);
char	**ft_split(char const *s, char c);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_error(int error, t_data *data);

//start_pipe
void	set_pipe(t_data *data, int i);
void	start_pipe(t_data *data);
void	re_pipe(t_data *data, int i);

//set_data
void	close_all(t_data *data);
void	first_cmd(t_data *data, int i);
void	mid_cmd(t_data *data, int i);
void	last_cmd(t_data *data, int i);
#endif