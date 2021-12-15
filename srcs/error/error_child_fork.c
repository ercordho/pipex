/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:47:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 16:26:32 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

static void	clean_memory(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdel((void **)&cmd->cmds_paths[0]);
	ft_memdel((void **)&cmd->cmds_paths[1]);
}

void	error_child_fork(t_cmd *cmd, const char *str)
{
	clean_memory(cmd);
	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (cmd->infile != 0)
		cmd->infile = close(cmd->infile);
	if (cmd->outfile != 0)
		cmd->outfile = close(cmd->outfile);
	if (cmd->end[0] == -1)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] == -1)
		error_close_file(NULL, "cmd->end[1]");
	if (cmd->infile == -1)
		error_close_file(NULL, "cmd->infile");
	if (cmd->outfile == -1)
		error_close_file(NULL, "cmd->outfile");
	ft_putstr(RED);
	ft_putendl("ERROR");
	ft_putstr(str);
	ft_putendl(" failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
