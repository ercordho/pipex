/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:07:56 by ercordho          #+#    #+#             */
/*   Updated: 2021/11/16 17:18:19 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define RED	"\x1B[31m"
# define NRML	"\x1B[0m"

typedef struct s_cmd
{
	int			end[2];
	const char	**paths;
	const char	**cmds[3];
	const char	*cmds_paths[3];
	const char	*tmp;
	int			infile;
	int			outfile;
}				t_cmd;

/*
**	ASCII
*/
int			ft_ischarset(const char *set, char c);

/*
**	ERROR
*/
void		error_access(const char *str);
void		error_child_dup2(t_cmd *cmd, const char *str);
void		error_child_fork(t_cmd *cmd, const char *str);
void		error_init_cmd(t_cmd *cmd, int index);
void		error_init_paths(void);
void		error_malloc_paths(t_cmd *cmd, int i);
void		error_open_file(t_cmd *cmd, int file_index);
void		error_pipe(void);
void		error_waitpid(const char **cmds[3]);

/*
**	INIT
*/
void		init_pipex(t_cmd *cmd, const char **envp, const char **argv);

/*
**	MEMORY
*/
void		ft_memdel(void **ptr);
void		ft_memdels(void **ptr, void **content);
void		*ft_memset(void *ptr, int c, size_t end);

/*
**	STRING
*/
int			countwords(const char *str, const char *set);
char		**ft_split(const char *str, const char *set);
char		*ft_strdup(const char *str);
char		*ft_strjoinsep(const char *str_1, const char *str_2, int c);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *str, int c);

/*
**	WRITE
*/
size_t		ft_putchar(char c);
size_t		ft_putendl(const char *str);
size_t		ft_putstr(const char *str);

/*
**	PIPEX
*/
void		pipex(t_cmd *cmd, const char **envp, const char **argv);

#endif
