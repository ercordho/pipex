/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:18:34 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 16:26:39 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_close_file(t_cmd *cmd, const char *file_name)
{
	int	i;

	if (cmd)
	{
		i = -1;
		while (cmd->cmds[++i])
			ft_memdels((void **)&cmd->cmds[i], (void **)cmd->cmds[i]);
		ft_memdel((void **)&cmd->cmds_paths[0]);
		ft_memdel((void **)&cmd->cmds_paths[1]);
	}
	ft_putstr(RED);
	ft_putstr("ERROR\nError closing file: ");
	ft_putstr(file_name);
	ft_putendl(".");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
