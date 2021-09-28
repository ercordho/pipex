/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:52:04 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:54:06 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memset(void *ptr, int c, size_t start, size_t end)
{
	if (ptr == NULL)
		return (NULL);
	while (start < end)
		*(unsigned char *)(ptr + start++) = (unsigned char)c;
	return (ptr);
}
