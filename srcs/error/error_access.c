/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:30:02 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/16 17:05:56 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	error_access(const char *str)
{
	ft_putstr(RED);
	ft_putstr("ERROR\nIncomplete user permission for ");
	ft_putstr(str);
	ft_putendl(".");
	ft_putstr(NRML);
	exit(EXIT_FAILURE);
}
