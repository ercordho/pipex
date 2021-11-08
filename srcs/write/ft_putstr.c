/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:59 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 16:34:33 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

size_t	ft_putstr(const char *str)
{
	size_t	size;

	if (str == NULL)
		return (ft_putstr("(null)"));
	size = 0;
	while (*str)
		size += ft_putchar(*str++);
	return (size);
}
