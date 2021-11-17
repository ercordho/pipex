/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:47:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/17 18:09:10 by ercordho         ###   ########.fr       */
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
	close(cmd->end[0]);
	close(cmd->end[1]);
	close(cmd->infile);
	close(cmd->outfile);
	ft_putstr(RED);
	ft_putendl("ERROR");
	ft_putstr(str);
	ft_putendl(" failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
