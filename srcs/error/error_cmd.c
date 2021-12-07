/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:56:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/07 17:21:51 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_cmd(const char *cmd)
{
	ft_putstr(RED);
	ft_putstr("ERROR\npipex: ");
	ft_putstr(cmd);
	ft_putendl(": command not found.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
