/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:52:32 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:32 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>
# include "./printf/ft_printf.h"

int	g_status;

typedef struct s_envp
{
	char				*key;
	char				*value;
	int					idx;
	struct s_envp		*next;
}	t_envp;

typedef struct s_infile
{
	int						is_heredoc;
	char					*file;
	struct s_infile			*next;
}	t_infile;

typedef struct s_outfile
{
	char					*file;
	int						type;
	struct s_outfile		*next;
}	t_outfile;

typedef struct s_cmd
{
	int					idx;
	char				**cmd;
	t_infile			*infile;
	t_outfile			*outfile;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_parse
{
	int				pipe;
	int				type;
	char			*token;
	struct s_parse	*next;
}	t_parse;

typedef struct s_main
{
	t_envp			*ev_lst;
	char			*home;
	int				stdin_fd;
	int				stdout_fd;
	int				cmd_num;
	int				status;
	t_infile		*heredoc;
	t_parse			*parse;
	t_cmd			*cmd_head;
	t_cmd			*curr;
}	t_main;

typedef struct s_state
{
	int		type;
	int		pipe;
	int		sq;
	int		dq;
	int		sq_heredoc;
	int		syn_error;
	int		inred_idx;
	int		outred_idx;
	int		dollar;
	int		space;
	int		index;
	int		dollar_space;
	char	*newline;
	char	str[100000];
}	t_state;

enum e_error
{
	PWD_ERROR,
	UNSET_ERROR,
	EXPORT_ERROR,
	EXIT_MANY_ARG_ERROR,
	EXIT_NOT_DIGIT_ERROR,
	QOUTE_ERROR,
	ENV_ERROR,
	CD_NO_PATH_ERROR,
	PERMISSION_ERROR,
	IN_NOFILE_ERROR,
	OPEN_ERROR,
	NO_EXIST_CMD_ERROR,
	NOT_SET_OLDPWD_ERROR,
	NOT_SET_HOME_ERROR,
	NOT_LL_ERROR,
	IS_A_DIRECTORY,
	NOT_A_DIRECTORY,
};

enum e_type
{
	CMD,
	INFILE,
	HEREDOC,
	OUTFILE,
	OUTAP,
};

//parse
//create_node
void		create_infile(t_main *main, char *token, int type);
void		create_outfile(t_main *main, char *token, int type);
void		create_heredoc(t_main *main, char *file);
//init_cmd
void		init_cmd(t_main *main, int pipe, t_parse *p_curr);
char		*create_file_node(t_main *main, t_parse *p_curr);
void		make_cmd_node(t_main *main, int i);
char		**cmd_node_split(t_main *main, int pipe);
//init_main
void		init_main(t_main *main, char *line);
void		check_cmd_num(t_main *main, t_cmd *curr);
//init_parse
int			check_quote(t_main *main, t_state *stat);
void		init_parse(t_main *main, char *line, int i);
char		*parse_line(t_main *main, char *line, int *i, t_state *stat);
void		ft_parse(t_main *main, char *line, int i, t_state *stat);
void		init_state(t_state *stat);

//dollar
void		parse_dollar(t_main *main, char *line, int i, t_state *stat);
int			find_key_len(char *line, int i);
char		*ft_midjoin(int i, char *line, char *value, int key_len);
void		put_newline(char *newline, char *line, char *value, int i);
char		*change_key_value(t_main *main, char *line, int i, int key_len);
//envp
t_envp		*parse_envp(char **env_input, int i);
t_envp		*create_env(char **env, int i);
//in_red
void		parse_in_red(char *line, t_main *main, int i, t_state *stat);
int			check_infile(char *line, t_main *main, int i, t_state *stat);
//letter
void		parse_letter(char *line, int i, t_state *stat);
//out_red
void		parse_out_red(char *line, t_main *main, int i, t_state *stat);
int			check_outfile(char *line, t_main *main, int i, t_state *stat);
//pipe
void		parse_pipe(char *line, t_main *main, int i, t_state *stat);
//space
void		parse_space(t_main *main, t_state *stat);
void		make_new_token(t_main *main, t_state *stat);
void		put_token(t_parse *new, char *str);
//heredoc
void		change_file(char *file, int i);
char		*heredoc_parse_dollar(t_main *main, char *line, int i);
char		*check_file(void);
void		run_heredoc(t_main *main, t_state *stat, int fd, int i);
void		make_heredoc_file(t_main *main, t_state *stat, int fd, int i);

//utils
long long	ft_atoll(t_main *main, const char *str, int sign);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
char		**make_split(char const *s, char c, char **split_word);
int			num_word(char const *s, char c);
int			num_letter(char const *s, char c, int i);
char		**split_free(char **split_word);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin3(char *s1, char *s2, char *s3);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
void		ft_putstr_fd_free(char *s, int fd);
//exec utils
void		free_env(char **env);
int			check_ab_path(char	*cmd);
char		**change_lst_env(t_main *main, t_envp *curr);
void		ft_exec(char *cmd, t_main *main, char **env);
//heredoc utils
void		cursor(void);
void		put_str(char *str, char *file, int i);
//signal
void		exit_line(void);
void		set_signal(void);
//error
void		ft_error1(int code);
void		ft_error2(int code, char *str);
void		syntax_error(t_main *main, char *line, int i, t_state *stat);
int			check_tok(char *line, int i, char c);
void		syntax_error_null(t_main *main, t_state *stat);
//free
void		free_main(t_main *main);
void		free_infile(t_infile *infile);
void		free_outfile(t_outfile *outfile);
void		free_cmd(t_cmd *cmd);
void		free_parse(t_parse *parse);
void		free_heredoc(t_infile *heredoc);
void		free_cmd_strs(t_cmd *cmd);
//parse utils
int			change_idx(t_state *stat, int i);
void		put_newline_q(char *newline, char *line, char *value, int i);

//exec
//start_main
void		start_main(t_main *main);
void		clear_heredoc(t_main *main);
void		run_builtin(t_main *main);
int			check_builtin(char *cmd);
//run_pipe
void		run_pipe(t_main *main, int i, int status);
void		set_pipe(t_main *main, int *fds, int input_fd, int index);
int			re_pipe(int *fds, int input_fd);
//run_exec
void		run_exec(t_main *main);
char		**create_path(t_main *main);
int			check_access(char *path);
char		*find_path(t_main *main, char **paths, int i, int file_deny);
void		access_ab_path(t_main *main, char **env);
//redirect
int			ft_redirect(t_main *main);
int			inf_redirect(t_main *main);
int			outf_redirect(t_main *main);

//builtin
//ft_echo
void		ft_echo(t_main *main);
int			check_n(char *str);
//ft_env
void		ft_env(t_main *main);
void		print_env(char *key, char *value);
//ft_exit
void		ft_exit(t_main *main, int exit_status);
int			check_not_digit(char *str);
//ft_pwd
void		ft_pwd(t_main *main);
//ft_unset
void		ft_unset(t_main *main);
void		remove_envp(t_envp *curr, t_envp *pre, char *cmd);
int			check_unset(char *str);
//ft_cd
void		ft_cd(t_main *main);
void		chdir_pre(t_main *main);
void		chdir_home(t_main *main);
char		*save_home(t_envp *ev_lst);
//ft_export
void		ft_export(t_main *main);
void		add_ev_lst(char *str, t_main *main);
void		ft_swap(t_envp *a, t_envp *b);
void		sort_env(t_main *main);
void		print_export(t_envp *ev_lst);
int			check_valid(char *str);
char		*get_value(char *str, int i, int j);
char		*get_key(char *str);
void		create_env_node(char *key, char *value, t_main *main);
#endif