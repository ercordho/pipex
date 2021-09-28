/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:17:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:58:59 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_putendls(const char **strs)
{
	size_t	size;
	int		i;

	if (strs == NULL)
		return (ft_putendl("(null"));
	size = 0;
	i = -1;
	while (strs[++i])
		size += ft_putendl(strs[i]);
	return (size);
}
