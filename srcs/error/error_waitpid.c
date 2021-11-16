/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_waitpid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:04:12 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/16 17:23:16 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_waitpid(const char **cmds[3])
{
	int	i;

	i = -1;
	while (cmds[++i])
		ft_memdels((void **)&cmds[i], (void **)cmds[i]);
	ft_putstr(RED);
	ft_putendl("ERROR\nWaitpid failure.");
	ft_putchar('.');
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
