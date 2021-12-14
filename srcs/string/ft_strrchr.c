/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:50:10 by ercordho          #+#    #+#             */
/*   Updated: 2021/12/14 17:02:47 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	if (str == (void *)0)
		return (NULL);
	len = ft_strlen(str);
	while (--len > 0)
	{
		if (str[len] == (char)c)
			return ((char *)(str + len));
	}
	return (NULL);
}
