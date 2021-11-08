/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:24:21 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/08 19:31:08 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipex.h"

char	*ft_strjoinsep(const char *str_1, const char *str_2, int c)
{
	size_t	len;
	char	*new_str;
	int		i;

	if (str_1 == NULL || str_2 == NULL)
		return (NULL);
	len = ft_strlen(str_1) + ft_strlen(str_2);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	new_str = (char *)ft_memset((void *)new_str, '\0', len + 2);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*str_1)
		new_str[i++] = *str_1++;
	new_str[i++] = (char)c;
	while (*str_2)
		new_str[i++] = *str_2++;
	return (new_str);
}
