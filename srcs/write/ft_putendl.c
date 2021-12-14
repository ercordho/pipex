/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:29 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/14 23:52:10 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

size_t	ft_putendl(const char *str)
{
	if (str == (void *)0)
	{
		if (__APPLE__)
			return (ft_putendl("(null)"));
		return (ft_putendl("(nil)"));
	}
	return (ft_putstr(str) + ft_putchar('\n'));
}
