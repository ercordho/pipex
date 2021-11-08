/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:01:52 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 23:33:38 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static void	init_pipex_cmds(t_cmd *cmd, const char **envp, const char **argv)
{
	int			i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			cmd->paths = (const char **)ft_split(envp[i], ":");
			if (cmd->paths == NULL)
				error_init_paths();
			break ;
		}
	}
	cmd->cmds[0] = (const char **)ft_split(argv[2], " ");
	cmd->cmds[1] = (const char **)ft_split(argv[3], " ");
	if (cmd->cmds[0] == NULL)
		error_init_cmd(cmd, 1);
	if (cmd->cmds[1] == NULL)
		error_init_cmd(cmd, 2);
	cmd->cmds[2] = NULL;
	cmd->cmds_paths[2] = NULL;
}

static void	init_pipex_paths(t_cmd *cmd, int i)
{
	int			j;

	if (access(cmd->cmds[i][0], F_OK) == 0)
	{
		cmd->cmds_paths[i] = (const char *)ft_strdup(cmd->cmds[i][0]);
		if (cmd->cmds_paths[i] == NULL)
			error_malloc_paths(cmd, i);
		cmd->tmp = (const char *)(ft_strrchr(cmd->cmds[i][0], (int) '/') + 1);
		if (cmd->tmp == NULL)
			error_malloc_paths(cmd, i);
		ft_memdel((void **)&cmd->cmds[i][0]);
		cmd->cmds[i][0] = (const char *)ft_strdup(cmd->tmp);
		ft_memdel((void **)&cmd->tmp);
		return ;
	}
	j = -1;
	while (cmd->paths[++j])
	{
		cmd->cmds_paths[i] = ft_strjoinsep(cmd->paths[j], cmd->cmds[i][0], '/');
		if (cmd->cmds_paths[i] == NULL)
			error_malloc_paths(cmd, i);
		if (access(cmd->cmds_paths[i], F_OK) == 0)
			return ;
		ft_memdel((void **)&cmd->cmds_paths[i]);
	}
}

void	init_pipex(t_cmd *cmd, const char **envp, const char **argv)
{
	int	i;

	init_pipex_cmds(cmd, envp, argv);
	i = -1;
	while (++i < 2)
		init_pipex_paths(cmd, i);
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	i = -1;
	while (cmd->cmds[++i])
	{
		printf("cmd->cmds[%i][0] = %s\n", i, cmd->cmds[i][0]);
		printf("cmd->cmds[%i][1] = %s\n", i, cmd->cmds[i][1]);
	}
}
