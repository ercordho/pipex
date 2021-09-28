/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:09:35 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 16:25:12 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/inc/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>  
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_cmd
{
	const char	**paths;
	const char	*first_cmd;
	const char	*second_cmd;
}				t_cmd;

#endif
