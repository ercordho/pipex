/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:20:27 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/17 17:32:56 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_init_cmd(t_cmd *cmd, int index)
{
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	ft_putstr(RED);
	if (index == 1)
		ft_putendl("ERROR\nError when initialising Command 1.");
	else if (index == 2)
	{
		ft_memdels((void **)&cmd->cmds[0], (void **)cmd->cmds[0]);
		ft_putendl("ERROR\nError when initialising Command 2.");
	}
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
