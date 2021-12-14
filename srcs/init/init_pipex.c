/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:01:52 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 00:04:48 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static void	init_file_descriptor(t_cmd *cmd)
{
	cmd->end[0] = 0;
	cmd->end[1] = 0;
	cmd->infile = 0;
	cmd->outfile = 0;
}

static void	init_pipex_cmds(t_cmd *cmd, const char **envp, const char **argv)
{
	int			i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			cmd->paths = (const char **)ft_split(envp[i] + 5, ":");
			if (cmd->paths == (void *)0)
				error_init_paths();
			break ;
		}
	}
	cmd->cmds[0] = (const char **)ft_split(argv[2], " ");
	cmd->cmds[1] = (const char **)ft_split(argv[3], " ");
	if (cmd->cmds[0] == (void *)0)
		error_init_cmd(cmd, 1);
	if (cmd->cmds[1] == (void *)0)
		error_init_cmd(cmd, 2);
	cmd->cmds[2] = NULL;
	i = -1;
	while (++i < 3)
		cmd->cmds_paths[i] = NULL;
}

static void	init_pipex_paths(t_cmd *cmd, int i, int j)
{
	if (access(cmd->cmds[i][0], F_OK) == 0)
	{
		cmd->cmds_paths[i] = (const char *)ft_strdup(cmd->cmds[i][0]);
		if (cmd->cmds_paths[i] == (void *)0)
			error_malloc_paths(cmd);
		cmd->tmp = (const char *)ft_strrchr(cmd->cmds[i][0], (int) '/') + 1;
		cmd->tmp = (const char *)ft_strdup(cmd->tmp);
		ft_memdel((void **)&cmd->cmds[i][0]);
		cmd->cmds[i][0] = (const char *)ft_strdup(cmd->tmp);
		ft_memdel((void **)&cmd->tmp);
		if (cmd->cmds[i][0] == (void *)0)
			error_malloc_paths(cmd);
		return ;
	}
	j = -1;
	while (cmd->paths[++j])
	{
		cmd->cmds_paths[i] = ft_strjoinsep(cmd->paths[j], cmd->cmds[i][0], '/');
		if (cmd->cmds_paths[i] == (void *)0)
			error_malloc_paths(cmd);
		if (access(cmd->cmds_paths[i], F_OK) == 0)
			return ;
		ft_memdel((void **)&cmd->cmds_paths[i]);
	}
	cmd->cmds_paths[i] = NULL;
}

void	init_pipex(t_cmd *cmd, const char **envp, const char **argv)
{
	int	i;

	init_file_descriptor(cmd);
	init_pipex_cmds(cmd, envp, argv);
	i = -1;
	while (++i < 2)
		init_pipex_paths(cmd, i, -1);
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	if (pipe(cmd->end) == -1)
		error_pipe(cmd);
	if (cmd->cmds_paths[0] == (void *)0)
		cmd->infile = -1;
	else
	{
		cmd->infile = open(argv[1], O_RDONLY);
		if (cmd->infile == -1)
			error_open_file(cmd, 1);
	}
	cmd->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile == -1)
		error_open_file(cmd, 2);
}
