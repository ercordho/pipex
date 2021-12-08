/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:56:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/08 17:32:57 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_cmd(t_cmd *cmd, const char *command)
{
	int	i;

	ft_putstr(RED);
	ft_putstr("ERROR\npipex: ");
	ft_putstr(command);
	ft_putendl(": command not found.");
	ft_putstr(NRML);
	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	ft_memdel((void **)&cmd->cmds_paths[0]);
	ft_memdel((void **)&cmd->cmds_paths[1]);
	exit(EXIT_FAILURE);
}
