/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:37:37 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:53:55 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_memdels(void **ptr, void **content)
{
	if (ptr && content)
	{
		while (*content)
			ft_memdel(&(*content++));
		ft_memdel(&(*ptr));
	}
}
