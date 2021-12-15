/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_waitpid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:04:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 16:27:37 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_waitpid(t_cmd *cmd)
{
	int	i;

	ft_putstr(RED);
	ft_putendl("ERROR\nError during the waitpid call.");
	ft_putstr(NRML);
	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdel((void **)&cmd->cmds_paths[0]);
	ft_memdel((void **)&cmd->cmds_paths[1]);
	exit(EXIT_FAILURE);
}
