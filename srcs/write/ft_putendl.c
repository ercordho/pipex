/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:33:29 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 16:34:30 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

size_t	ft_putendl(const char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)\n"));
	return (ft_putstr(str) + ft_putchar('\n'));
}
