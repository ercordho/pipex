/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_open_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:36:15 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 16:27:23 by ercordho         ###   ########.fr       */
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

void	error_open_file(t_cmd *cmd, int file_index)
{
	clean_memory(cmd);
	ft_putstr(RED);
	if (file_index == -1)
		ft_putendl("ERROR\nOpening file 1 failed.");
	else if (file_index == 2)
	{
		ft_putendl("ERROR\nOpening file 2 failed.");
		if (cmd->infile != 0)
			cmd->infile = close(cmd->infile);
	}
	ft_putstr(NRML);
	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (cmd->infile == -1)
		error_close_file(NULL, "cmd->infile");
	if (cmd->end[0] == -1)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] == -1)
		error_close_file(NULL, "cmd->end[1]");
	exit(EXIT_FAILURE);
}
