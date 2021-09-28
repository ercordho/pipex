/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:59:47 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:58:25 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strslen(const char **strs)
{
	size_t	len;

	if (strs == NULL)
		return (0);
	len = 0;
	while (strs[len])
		len++;
	return (len);
}
