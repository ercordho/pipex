/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_open_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:36:15 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/17 18:07:21 by ercordho         ###   ########.fr       */
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
	close(cmd->end[0]);
	close(cmd->end[1]);
	ft_putstr(RED);
	if (file_index == 1)
		ft_putendl("ERROR\nOpening file 1 failed.");
	else if (file_index == 2)
	{
		close(cmd->infile);
		ft_putendl("ERROR\nOpening file 2 failed.");
	}
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
