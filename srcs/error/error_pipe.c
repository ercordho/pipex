/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:28:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/16 16:42:30 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_pipe(void)
{
	ft_putstr(RED);
	ft_putendl("ERROR\nPipe failled.");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
