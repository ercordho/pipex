/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:06:39 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:53:56 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)n)
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
	return (dst);
}
