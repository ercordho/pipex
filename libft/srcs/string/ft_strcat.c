/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:39:19 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:58:28 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	i;

	if (dst == NULL)
		return (NULL);
	if (src == NULL)
		return (dst);
	dst_len = ft_strlen(dst);
	i = 0;
	while (*src)
		dst[dst_len + i++] = *src++;
	dst[dst_len + i] = '\0';
	return (dst);
}
