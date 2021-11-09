/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:47:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/09 03:51:26 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_child_fork(t_cmd *cmd, int child_index)
{
	int	i;

	i = -1;
	while (cmd->cmds[i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_putstr(RED);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	if (child_index == 1)
		ft_putendl("ERROR\nChild 1 fork failled.");
	else if (child_index == 2)
		ft_putendl("ERROR\nChild 2 fork failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
