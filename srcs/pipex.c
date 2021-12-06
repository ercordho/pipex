/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:36:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/06 17:15:21 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	clean_memory(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, 1);
	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, 1);
}

static void	child_process_1(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, 1);
	if (dup2(cmd->end[1], STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, 1);
	if (dup2(cmd->infile, STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	if (close(cmd->infile) == -1)
		error_close_file(cmd, 1);
	f = &execve;
	f(cmd->cmds_paths[0], (char *const *)cmd->cmds[0], (char *const *)envp);
}

static void	child_process_2(t_cmd *cmd, const char **envp)
{
	int	(*f)(const char *, char *const *, char *const *);

	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, 1);
	if (dup2(cmd->end[0], STDIN_FILENO) < 0)
		error_child_dup2(cmd);
	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, 1);
	if (dup2(cmd->outfile, STDOUT_FILENO) < 0)
		error_child_dup2(cmd);
	if (close(cmd->outfile) == -1)
		error_close_file(cmd, 1);
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
