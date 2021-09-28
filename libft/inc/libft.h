/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:50:17 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 16:22:17 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**	GNL BUFFER
*/
# define BUFFER_SIZE	1

/*
**	ASCII
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_ischarset(const char *set, char c);
int			ft_isdigit(int c);

/*
**	MEMORY
*/
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ptr);
void		ft_memdels(void **ptr, void **content);
void		*ft_memset(void *ptr, int c, size_t start, size_t end);
void		*ft_memsetmalloc(int c, size_t len);
void		*ft_realloc(void *ptr, size_t n_size, size_t o_size);
void		ft_swap(void *a, void *b);

/*
**	READ
*/
int			get_next_line(int file_descriptor, char **line);

/*
**	STRING
*/
int			ft_countwords(const char *str, const char *set);
char		**ft_split(const char *str, const char *set);
char		*ft_strcat(char *dst, const char *src);	
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *str_1, const char *str_2);
void		ft_strrev(char *str);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strslen(const char **strs);
char		*ft_strsub(const char *str, size_t start, size_t len);

/*
**	WRITE
*/
size_t		ft_putchar(char c);
size_t		ft_putendl(const char *str);
size_t		ft_putendls(const char **strs);
size_t		ft_putnbr(long nbr);
size_t		ft_putstr(const char *str);
size_t		ft_putstrs(const char **strs);

#endif
