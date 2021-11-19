/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:56:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/18 18:53:53 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_cmd(t_cmd *cmd)
{
	int	j;

	j = -1;
	while (cmd->cmds[++j])
		ft_memdels((void **)&cmd->cmds[j], (void **)cmd->cmds);
	ft_putstr(RED);
	ft_putendl("ERROR\nCommand not found.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
