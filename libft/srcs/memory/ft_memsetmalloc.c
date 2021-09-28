/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetmalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 01:20:38 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 12:08:52 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memsetmalloc(int c, size_t len)
{
	void	*ptr;

	ptr = malloc(sizeof(void) * len);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, c, 0, len));
}
