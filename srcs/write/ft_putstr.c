/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:59 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/02 00:17:34 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

size_t	ft_putstr(const char *str)
{
	size_t	size;

	if (str == (void *)0)
	{
		if (__APPLE__)
			return (ft_putstr("(null)"));
		return (ft_putstr("(nil)"));
	}
	size = 0;
	while (*str)
		size += ft_putchar(*str++);
	return (size);
}
