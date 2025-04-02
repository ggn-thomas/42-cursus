/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:39:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/04/02 14:35:09 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_command_in_path(const char *cmd, const char *path)
{
	char	**dirs;
	char	*full_path;
	char	*tmp;
	int		i;

	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	full_path = malloc(1024);
	if (!full_path)
	{
		ft_free_split(dirs);
		return (NULL);
	}
	i = 0;
	while (dirs[i])
	{
		tmp = ft_strjoin(dirs[i], "/");
		ft_strlcpy(full_path, tmp, 1024);
		free(tmp);
		tmp = ft_strjoin(full_path, cmd);
		ft_strlcpy(full_path, tmp, 1024);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(dirs);
			return (full_path);
		}
		i++;
	}
	ft_free_split(dirs);
	free(full_path);
	return (NULL);
}

char	**tab_args(t_command *index)
{
	char	**argv;
	t_line	*arg_node;
	int		arg_count;
	int		i;

	arg_count = 0;
	arg_node = *(index->args);
	while (arg_node)
	{
		arg_count++;
		arg_node = arg_node->next;
	}
	argv = malloc(sizeof(char *) * (arg_count + 2));
	if (!argv)
		return (NULL);
	argv[0] = ft_strdup(index->command);
	arg_node = *(index->args);
	i = 1;
	while (arg_node)
	{
		argv[i++] = ft_strdup(arg_node->data);
		arg_node = arg_node->next;
	}
	argv[i] = NULL;
	return (argv);
}

void	ft_execve(t_command *index)
{
	pid_t		pid;
	int			status;
	char		**argv;
	extern char	**environ;
	char		*path;
	char		*full_path;

	// char *argv[] = {index->command, NULL};
	argv = tab_args(index);
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return ;
	}
	else if (pid == 0)
	{
		path = getenv("PATH");
		full_path = find_command_in_path(index->command, path);
		if (full_path)
		{
			if (execve(full_path, argv, environ) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", index->command);
			exit(EXIT_FAILURE);
		}
		ft_free_tab(argv);
	}
	else
	{
		waitpid(pid, &status, 0);
		ft_free_tab(argv);
	}
}

void	ft_execve_pipe(t_command *index)
{
	char		**argv;
	extern char	**environ;
	char		*path;
	char		*full_path;

	argv = tab_args(index);
	path = getenv("PATH");
	full_path = find_command_in_path(index->command, path);
	if (full_path)
	{
		if (execve(full_path, argv, environ) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", index->command);
		exit(EXIT_FAILURE);
	}
	ft_free_tab(argv);
}
