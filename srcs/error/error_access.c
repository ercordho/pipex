/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:30:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/15 00:15:22 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_access(const char *file_name)
{
	ft_putstr(RED);
	ft_putstr("ERROR\nYou do not have the rights for the file: ");
	ft_putstr(file_name);
	ft_putendl(".");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
