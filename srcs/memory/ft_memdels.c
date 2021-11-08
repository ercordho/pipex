/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:48:59 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 16:49:31 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

void	ft_memdels(void **ptr, void **content)
{
	if (ptr && content)
	{
		while (*content)
			ft_memdel(&(*content++));
		ft_memdel(&(*ptr));
	}
}
