/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:28:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 17:08:32 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_pipe(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	ft_putstr(RED);
	ft_putendl("ERROR\nPipe failled.");
	ft_putstr(NRML);
	if (cmd->end[0] != 0)
		cmd->end[0] = close(cmd->end[0]);
	if (cmd->end[1] != 0)
		cmd->end[1] = close(cmd->end[1]);
	if (cmd->end[0] == -1)
		error_close_file(NULL, "cmd->end[0]");
	if (cmd->end[1] == -1)
		error_close_file(NULL, "cmd->end[1]");
	exit(EXIT_FAILURE);
}
