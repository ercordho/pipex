/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:47:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/06 15:57:55 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_child_fork(t_cmd *cmd, const char *str)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, 1);
	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, 1);
	if (close(cmd->infile) == -1)
		error_close_file(cmd, 1);
	if (close(cmd->outfile) == -1)
		error_close_file(cmd, 1);
	ft_putstr(RED);
	ft_putendl("ERROR");
	ft_putstr(str);
	ft_putendl(" failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
