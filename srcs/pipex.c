/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:36:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/09 00:11:32 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	child_process_1(t_cmd *cmd, const char **argv, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	close(cmd->end[0]);
	if (dup2(cmd->end[1], STDOUT_FILENO) < 0)
		error_child_dup2(cmd, 11);
	close(cmd->end[1]);
	cmd->infile = open(argv[1], O_RDONLY);
	if (cmd->infile == -1)
		error_open_file(cmd, 1);
	if (dup2(cmd->infile, STDIN_FILENO) < 0)
		error_child_dup2(cmd, 12);
	f = &execve;
	f(cmd->cmds_paths[0], (char *const *)cmd->cmds[0], (char *const *)envp);
}

static void	child_process_2(t_cmd *cmd, const char **argv, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	cmd->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile == -1)
		error_open_file(cmd, 2);
	close(cmd->end[1]);
	if (dup2(cmd->end[0], STDIN_FILENO) < 0)
		error_child_dup2(cmd, 21);
	close(cmd->end[0]);
	if (dup2(cmd->outfile, STDOUT_FILENO) < 0)
		error_child_dup2(cmd, 22);
	f = &execve;
	f(cmd->cmds_paths[1], (char *const *)cmd->cmds[1], (char *const *)envp);
}

void	pipex(t_cmd *cmd, const char **envp, const char **argv)
{
	pid_t	child_1;
	pid_t	child_2;
	int		i;

	init_pipex(cmd, envp, argv);
	child_1 = fork();
	if (child_1 < 0)
		error_child_fork(cmd, 1);
	if (child_1 == 0)
		child_process_1(cmd, argv, envp);
	child_2 = fork();
	if (child_2 < 0)
		error_child_fork(cmd, 2);
	if (child_2 == 0)
		child_process_2(cmd, argv, envp);
	waitpid(-1, NULL, 0);
	i = -1;
	while (cmd->cmds[i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	system("leaks pipex");
	exit(EXIT_SUCCESS);
}
