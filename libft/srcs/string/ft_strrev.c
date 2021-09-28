/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:50:21 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 12:52:01 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_strrev(char *str)
{
	size_t	str_len;
	int		i;

	str_len = ft_strlen((const char *)str);
	i = -1;
	while (++i < (int)str_len / 2)
		ft_swap(&str[i], &str[(int)str_len - i - 1]);
}
