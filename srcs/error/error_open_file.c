/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_open_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:36:15 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/13 17:46:02 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_open_file(t_cmd *cmd, int file_index)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	ft_putstr(RED);
	if (file_index == 1)
		ft_putendl("ERROR\nOpening file 1 failed.");
	else if (file_index == 2)
	{
		ft_putendl("ERROR\nOpening file 2 failed.");
		cmd->infile = close(cmd->infile);
	}
	ft_putstr(NRML);
	cmd->end[0] = close(cmd->end[0]);
	cmd->end[1] = close(cmd->end[1]);
	if (cmd->infile != 0)
		error_close_file(NULL, "cmd->infile");
	if (cmd->end[0] != 0)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] != 0)
		error_close_file(NULL, "cmd->end[1]");
	exit(EXIT_FAILURE);
}
