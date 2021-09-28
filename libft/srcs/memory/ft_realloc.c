/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:28:28 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:54:10 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_realloc(void *ptr, size_t n_size, size_t o_size)
{
	void	*n_ptr;

	n_ptr = malloc((sizeof(void) * (n_size + 1)));
	if (n_ptr)
		ft_memcpy(n_ptr, ptr, o_size);
	free(ptr);
	return (ft_memset(n_ptr, '\0', o_size, n_size));
}
