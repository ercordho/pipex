/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_dup2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:38:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/13 17:45:22 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_child_dup2(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	cmd->end[0] = close(cmd->end[0]);
	cmd->end[1] = close(cmd->end[1]);
	cmd->infile = close(cmd->infile);
	cmd->outfile = close(cmd->outfile);
	if (cmd->end[0] != 0)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] != 0)
		error_close_file(NULL, "cmd->end[1]");
	if (cmd->infile != 0)
		error_close_file(NULL, "cmd->infile");
	if (cmd->outfile != 0)
		error_close_file(NULL, "cmd->outfile");
	exit(EXIT_FAILURE);
}
