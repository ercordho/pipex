/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_dup2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:38:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/09 04:23:05 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_child_dup2(t_cmd *cmd, int process_index)
{
	int	i;

	i = -1;
	while (cmd->cmds[i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_putstr(RED);
	if (process_index == 11)
		ft_putendl("ERROR\nChild 1 dup2 STDOUT_FILENO failled.");
	if (process_index == 12)
		ft_putendl("ERROR\nChild 1 dup2 STDIN_FILENO failled.");
	if (process_index == 21)
		ft_putendl("ERROR\nChild 2 dup2 STDOUT_FILENO failled.");
	if (process_index == 22)
		ft_putendl("ERROR\nChild 2 dup2 STDIN_FILENO failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
