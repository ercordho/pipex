/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:07:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/14 23:11:23 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_malloc_paths(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmds[++i])
		ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	ft_memdels((void **)&cmd->cmds_paths, (void **)cmd->cmds_paths);
	ft_putstr(RED);
	ft_putendl("ERROR\nError malloc paths");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
