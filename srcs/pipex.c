/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:36:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/13 17:45:05 by ercordho         ###   ########.fr       */
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
	cmd->end[0] = close(cmd->end[0]);
	cmd->end[1] = close(cmd->end[1]);
	if (cmd->end[0] != 0)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] != 0)
		error_close_file(NULL, "cmd->end[1]");
}

static void	child_process_1(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	cmd->end[0] = close(cmd->end[0]);
	if (dup2(cmd->end[1], STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	cmd->end[1] = close(cmd->end[1]);
	if (dup2(cmd->infile, STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	cmd->infile = close(cmd->infile);
	if (cmd->end[0] != 0)
		error_close_file(cmd, "cmd->end[0]");
	if (cmd->end[1] != 0)
		error_close_file(cmd, "cmd->end[1]");
	if (cmd->infile != 0)
		error_close_file(cmd, "cmd->infile");
	f = &execve;
	f(cmd->cmds_paths[0], (char *const *)cmd->cmds[0], (char *const *)envp);
}

static void	child_process_2(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	cmd->end[1] = close(cmd->end[1]);
	if (dup2(cmd->end[0], STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	cmd->end[0] = close(cmd->end[0]);
	if (dup2(cmd->outfile, STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	cmd->outfile = close(cmd->outfile);
	if (cmd->end[1] != 0)
		error_close_file(cmd, "cmd->end[1]");
	if (cmd->end[0] != 0)
		error_close_file(cmd, "cmd->end[0]");
	if (cmd->outfile != 0)
		error_close_file(cmd, "cmd->outfile");
	f = &execve;
	f(cmd->cmds_paths[1], (char *const *)cmd->cmds[1], (char *const *)envp);
}

void	pipex(t_cmd *cmd, const char **envp, const char **argv)
{
	pid_t	child_1;
	pid_t	child_2;

	if (access(argv[1], F_OK) != 0)
		error_access();
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
	clean_memory(cmd);
}
