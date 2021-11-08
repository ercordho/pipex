/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:50:01 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 16:50:12 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

int	ft_ischarset(const char *set, char c)
{
	int		i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (i);
	}
	return (-1);
}
