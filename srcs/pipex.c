/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:36:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 16:14:59 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	clean_memory(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (cmd->end[0] == -1)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] == -1)
		error_close_file(NULL, "cmd->end[1]");
}

static void	child_process_1(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (dup2(cmd->end[1], STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (dup2(cmd->infile, STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	if (cmd->infile != 0)
		cmd->infile = close(cmd->infile);
	if (cmd->end[0] == -1)
		error_close_file(cmd, "cmd->end[0]");
	if (cmd->end[1] == -1)
		error_close_file(cmd, "cmd->end[1]");
	if (cmd->infile == -1)
		error_close_file(cmd, "cmd->infile 1");
	f = &execve;
	if (cmd->cmds_paths[0])
		f(cmd->cmds_paths[0], (char *const *)cmd->cmds[0], (char *const *)envp);
}

static void	child_process_2(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (dup2(cmd->end[0], STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (dup2(cmd->outfile, STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	if (cmd->outfile != 0)
		cmd->outfile = close(cmd->outfile);
	if (cmd->end[1] == -1)
		error_close_file(cmd, "cmd->end[1]");
	if (cmd->end[0] == -1)
		error_close_file(cmd, "cmd->end[0]");
	if (cmd->outfile == -1)
		error_close_file(cmd, "cmd->outfile");
	f = &execve;
	if (cmd->cmds_paths[1])
		f(cmd->cmds_paths[1], (char *const *)cmd->cmds[1], (char *const *)envp);
}

void	pipex(t_cmd *cmd, const char **envp, const char **argv)
{
	pid_t	child_1;
	pid_t	child_2;

	if (access(argv[1], F_OK) != 0)
		error_access(argv[1]);
	init_pipex(cmd, envp, argv);
	child_1 = fork();
	if (child_1 < 0)
		error_child_fork(cmd, "Child 1 fork");
	if (child_1 == 0)
		child_process_1(cmd, envp);
	child_2 = fork();
	if (child_2 < 0)
		error_child_fork(cmd, "Child 2 fork");
	if (child_2 == 0)
		child_process_2(cmd, envp);
	if (waitpid(-1, NULL, 0) == -1)
		error_waitpid(cmd);
	if (cmd->cmds_paths[0] == (void *)0)
		error_cmd(cmd, cmd->cmds[0][0]);
	if (cmd->cmds_paths[1] == (void *)0)
		error_cmd(cmd, cmd->cmds[1][0]);
	clean_memory(cmd);
}
