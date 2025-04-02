/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:37 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/01 15:03:38 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define MALLOC "Memory allocation failed !"
# define ERR_LIST "Error initializing list !"
# define ERR_RED "bash: syntax error near unexpected token `newline'"
# define ERR_DIRED "bash: syntax error near unexpected token `<<'"
# define ERR_DRED "bash: syntax error near unexpected token `>>'"
# define ERR_PIPE "bash: syntax error near unexpected token `|'"
# define ERROR "minishell: syntax error near unexpected token"
# define FD "Error to open file !"
# define PERM "Permission denied !"
# define REDIRECTION "1"

typedef enum s_mode
{
	WORD,
	PIPE,
	R_INPUT,
	R_OUTPUT,
	ECHO,
	CD,
	PWD,
	EEXPORT,
	EXIT,
	HERE_DOC,
	UNSET,
	ENV,
	DOUBLE_R,
}						t_mode;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	char				*str;
	struct s_env_var	*next;
}						t_env_var;

typedef struct s_line
{
	char				*data;
	t_mode				mode;
	struct s_line		*next;
}						t_line;

typedef struct s_command
{
	t_mode				mode;
	char				*command;
	t_line				**args;
	char				*outfile;
	char				*infile;
	int					in_fd;
	int					out_fd;
	struct s_command	*next;
	int					here_doc;
}						t_command;

// Tokenisation && parsing
t_command				**create_token(t_line **list_token);
char					**ft_split_operator(char const *s);
t_line					**check_operator_glued(char *str, t_line **line,
							char **tab_line);
t_command				**sort_arguments(char *line, t_env_var **env_cpy);
void					signal_handler(int signint);

// Utils parsing
int						have_operator_glued(char *str);
int						had_token_in_list(char *tab_line, t_line **list_token);
t_line					*ft_new_node(char *content);
void					ft_lst_add_back(t_line **lst, t_line *new);
t_line					*ft_lst_last(t_line *lst);
void					check_type(t_line *list_token);

// Free
void					ft_free_list(t_line **list);
void					ft_free_tab(char **str);
void					ft_free_list_cmd(t_command **list);
void					ft_free_list_env(t_env_var **lst);

// error
void					error(char *error_msg, char **tab_line,
							t_line **list_token, t_command **lst_cmd);
void					error_h(char *error_msg, t_line **line,
							t_line **list_token, t_command **lst_cmd);
void					error_l(char *error_msg, t_command **lst_cmd,
							t_env_var **env_cpy);
// Builtins
void					builtins(char *cmd);
int						is_builtin(char *cmd);
int						ft_cd(t_command *index);
void					ft_echo(t_command *index);
void					ft_pwd(void);
void					ft_env(t_env_var **env_cpy);
void					select_exec(t_command **list, t_env_var **env_cpy);
void					ft_execve(t_command *index);
void					ft_exit(t_command **list);
int						ft_unset(t_command *index, t_env_var **env_cpy);
int						ft_export(t_command *cmd, t_env_var **env_list);
int						is_valid_identifier(char *str);

// Exec
void					ft_free_split(char **split);
t_env_var				**load_environment(char **envp);
void					init_Rinput(t_line **current_token,
							t_command **lst_command, t_line **list_token,
							t_command *current_cmd);
void					init_Rouput(t_line **current_token,
							t_command **lst_command, t_line **list_token,
							t_command *current_cmd);
void					ft_here_doc(t_line **current_token, t_line **list_token,
							t_command *current_cmd, t_command **lst_command);
void					check_exec(t_command *index, t_command **lst_cmd,
							t_env_var **env_cpy);
int						ft_execute_pipe(t_command **lst, t_env_var **env_cpy);
void					ft_execve_pipe(t_command *index);
void					init_pipe(t_line **current_token, t_line **list_token,
							t_command **current_cmd, t_command **lst_command);
int						is_redirection(int mode);
void					add_argument(char *data, t_command *current_cmd,
							t_line **list_token, t_command **lst_cmd);
void					add_command(t_command *new_node,
							t_command **lst_command);
t_command				*init_command(void);
void					process_pipe(t_line **current_token,
							t_line **list_token, t_command **current_cmd,
							t_command **lst_command);

// Env
void					add_var(t_env_var *new_node, t_env_var **lst_command);

// Pipex
void					ft_execute(char **envp, char *command);
int						open_file(char *file, int mode);
char					*find_path(char **envp, char *command);
int						**init_fd(int count_pipe);
//int						*init_tab_pid(int count_command);
#endif