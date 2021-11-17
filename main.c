/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:06:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/17 18:12:20 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, const char **argv, const char **envp)
{
	t_cmd	cmd;

	if (argc == 5)
		pipex(&cmd, envp, argv);
	else
	{
		ft_putstr("ERROR\nExpected form of parameters: ");
		ft_putendl("./pipex file1 \"cmd1\" \"cmd2\" file2");
		return (EXIT_FAILURE);
	}
	system("leaks pipex");
	return (EXIT_SUCCESS);
}
