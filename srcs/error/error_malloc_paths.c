/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:07:46 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/17 18:06:04 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_malloc_paths(t_cmd *cmd, int i)
{
	ft_memdels((void **)&cmd->cmds_paths[0], (void **)cmd->cmds_paths[0]);
	if (i == 1)
		ft_memdels((void **)&cmd->cmds_paths[i], (void **)cmd->cmds_paths[i]);
	ft_memdels((void **)&cmd->paths, (void **)cmd->paths);
	ft_putstr(RED);
	ft_putendl("ERROR\nError malloc paths");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
