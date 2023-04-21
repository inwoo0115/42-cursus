/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:44:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/21 22:14:47 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h> //수정 바람

# define READ 1
# define WRITE 0

typedef struct s_data
{
	int		fds[2][2];
	int		status;
	int		inf_fd;
	int		outf_fd;
	int		cmd_num;
	char	*infile;
	char	*outfile;
	char	**paths;
	char	**envp;
	char	**cmd;
}	t_data;

//main
void	run_cmd(t_data *data, char *cmd);
void	get_path(t_data *data, char **envp);
void	init_data(t_data *data, int argc, char **argv, char **envp);

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

//start_pipe
void	close_pipe(t_data *data, int i);
void	set_pipe(t_data *data, int i);
void	start_pipe(t_data *data);

//set_data
void	set_data(t_data *data, int i);
void	close_all(t_data *data);
#endif