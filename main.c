/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:06:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 23:58:45 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, const char **argv, const char **envp)
{
	t_cmd	cmd;

	if (argc == 5)
	{
		if (pipe(cmd.end) == -1)
		{
			ft_putstr(RED);
			ft_putendl("ERROR\nPipe failled.");
			ft_putstr(NRML);
			return (EXIT_FAILURE);
		}
		if (access(argv[1], F_OK) != 0)
		{
			ft_putstr(RED);
			ft_putendl("ERROR\nFile 1 not found.");
			ft_putstr(NRML);
			return (EXIT_FAILURE);
		}
		pipex(&cmd, envp, argv);
	}
	else
	{
		ft_putendl("ERROR\nUsage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
