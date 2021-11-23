/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:06:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/23 15:03:27 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, const char **argv, const char **envp)
{
	t_cmd	cmd;

	if (argc == 5)
		pipex(&cmd, envp, argv);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
