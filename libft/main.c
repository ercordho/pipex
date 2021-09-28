/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:24:53 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 12:37:02 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	main(void)
{
	char	*str;

	str = ft_strsub("coucou les amis", 0, ft_strlen("coucou les amis"));
	ft_putendl((const char *)str);
	ft_memdel((void **)&str);
	free(str);
	return (0);
}
