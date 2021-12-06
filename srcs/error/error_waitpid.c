/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_waitpid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:04:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/06 15:58:18 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_waitpid(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	if (close(cmd->end[0]) == -1)
		error_close_file(cmd, 1);
	if (close(cmd->end[1]) == -1)
		error_close_file(cmd, 1);
	exit(EXIT_FAILURE);
}
