/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:18:34 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/06 15:56:34 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_close_file(t_cmd *cmd, int index)
{
	int	i;

	if (index == 1)
	{
		i = -1;
		while (cmd->cmds[++i])
			ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	}
	close(cmd->end[0]);
	close(cmd->end[1]);
	close(cmd->infile);
	close(cmd->outfile);
	exit(EXIT_FAILURE);
}
