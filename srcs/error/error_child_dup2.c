/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_dup2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:38:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/06 15:39:53 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_child_dup2(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, "end[0]", 1);
	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, "end[1]", 1);
	if (close(cmd->infile) == -1)
		error_close_file(cmd, "infile", 1);
	if (close(cmd->outfile) == -1)
		error_close_file(cmd, "outfile", 1);
	exit(EXIT_FAILURE);
}
