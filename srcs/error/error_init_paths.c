/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:07:30 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/13 16:09:08 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_init_paths(void)
{
	ft_putstr(RED);
	ft_putendl("ERROR\nError when initialising paths.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
