/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:44:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/28 18:13:18 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h> //수정 바람

# define READ 0
# define WRITE 1

typedef struct s_data
{
	int		fds[2][2];
	int		status;
	int		inf_fd;
	int		outf_fd;
	int		cmd_num;
	int		not_cmd;
	char	*infile;
	char	*outfile;
	char	**paths;
	char	**envp;
	char	**cmd;
}	t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				fd;
	int				index;
	int				len;
	char			buff[BUFFER_SIZE + 1];
}	t_list;

//main
int		free_res(t_data *data);
void	run_cmd(t_data *data, char *cmd);
void	get_path(t_data *data, char **envp, int i);
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
void	ft_error(char *str, t_data *data);

//start_pipe
void	set_pipe(t_data *data, int i);
void	start_pipe(t_data *data);
void	re_pipe(t_data *data, int i);

//set_data
void	close_all(t_data *data);
void	first_cmd(t_data *data, int i);
void	mid_cmd(t_data *data, int i);
void	last_cmd(t_data *data, int i);

//gnl
char	*get_next_line(int fd);
char	*make_line(char	*str);
char	*get_newline(int fd, char *buff, t_list *data, int len);
char	*find_data(t_list *data, int i);
int		check_newline(char *str, t_list *data, int i, int j);

//heredoc
void	ft_heredoc(t_data *data, char *limiter);
void	init_heredoc(t_data *data, int argc, char **argv, char **envp);
void	change_file(char *filename, int i);

#endif