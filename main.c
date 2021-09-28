/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:34 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/25 23:58:49 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_core/inc/pipex.h"

int	get_cmds(const char *argv, t_cmd *cmd, const char **envp)
{
	const char	**commands;
	int	i;
	char		*cmd_path;

	(void)envp;
	commands = (const char **)ft_split(argv, " ");
	if (commands == NULL)
		return (-1);
	i = -1;
	while (cmd->paths[++i])
	{
		cmd_path = ft_strjoin(cmd->paths[i], argv);
		if (cmd_path == NULL)
			return (-1);
	//	execve(cmd_path, commands, envp);
	}
	ft_putendl(cmd_path);
	ft_memdel((void **)&cmd_path);
	return (1);
}
/*
int	parent_process(int fd_2, char *cmd_2, int end[2])
{
	int	status;

	if (dup2(fd_2, STDOUT_FILENO) < 0)
	{
		close(end[1]);
		close(fd_2);
		return (EXIT_FAILURE);
	}
	if (dup2(end[0], STDIN_FILENO) < 0)
	{
		close(end[1]);
		close(fd_2);
		return (EXIT_FAILURE);
	}
	close(end[1]);
	close(fd_2);
	return (EXIT_SUCCESS);
}

int	child_process(int fd_1, char *cmd_1, int end[2])
{
	(void)cmd_1;
	if (dup2(fd_1, STDIN_FILENO) < 0)
	{
		close(end[0]);
		close(fd_1);
		perror(errno);
		return (EXIT_FAILURE);
	}
	if (dup2(end[1], STDOUT_FILENO) < 0)
	{
		close(end[0]);
		close(fd_1);
		perror(errno);
		return (EXIT_FAILURE);
	}
	close(end[0]);
	close(fd_1);
	return (EXIT_SUCCESS);
}

void	pipex(int fd_1, int fd_2, char **argv, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	if (pipe(end) == -1)
		return ;
	child_1 = fork();
	if (child_1 < 0)
		return ;
	if (child_1 == 0)
	{
//		child_process_1;
	}
	child_2 = fork();
	if (child_2 < 0)
		return ;
	if (child_2 == 0)
	{
//		child_process_2;
	}
	close(end[0]);
	close(end[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
}
*/
int	get_paths(const char **envp, t_cmd *cmd)
{
	int	i;
	
	i = -1;
	cmd->paths = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			cmd->paths = (const char **)ft_split(envp[i] + 5, ":");
			break ;
		}
	}
	ft_putendls(cmd->paths);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_1;
	int		fd_2;
	t_cmd	cmd;

	ft_putnbr((long)argc);
	ft_putchar('\n');
	if (argc == 5)
	{
		get_paths((const char **)envp, &cmd);
		get_cmds(argv[1], &cmd, (const char **)envp);
		get_cmds(argv[2], &cmd, (const char **)envp);
		(void)argv;
		(void)fd_1;
		(void)fd_2;
	/*
		fd_1 = open(argv[1], O_RDONLY);
		fd_2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd_1 == -1 || fd_2 == -1)
			return (-1);
	*/
	//	pipex(fd_1, fd_2, argv, envp);
	}
	return (0);
}
