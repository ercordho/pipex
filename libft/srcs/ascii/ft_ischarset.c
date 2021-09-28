/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:09:09 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:51:16 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
