/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:38:47 by ercordho          #+#    #+#             */
/*   Updated: 2021/09/23 11:57:08 by ercordho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	clean_memory(void *ptr, int val)
{
	free(ptr);
	return (val);
}

static int	read_line(char **line, char *buffer, int loop, int len)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = *line;
	j = -1;
	*line = (char *)malloc(sizeof(char) * (BUFFER_SIZE * loop + 1));
	if (line == NULL)
		return (clean_memory((void *)tmp, -1));
	i = -1;
	while (tmp && tmp[++i])
		(*line)[i] = tmp[i];
	if (i < 0)
		i = 0;
	j = -1;
	while (++j < len)
		(*line)[i + j] = buffer[j];
	(*line)[i + j] = '\0';
	if (buffer[j])
		j++;
	i = 0;
	while (buffer[j])
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
	return (clean_memory((void *)tmp, 1));
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		can_be_read;
	int			loop;
	int			len;

	if (line == NULL || (BUFFER_SIZE < 1 || read(fd, buffer, 0)))
		return (-1);
	can_be_read = 1;
	loop = 0;
	while (can_be_read)
	{
		if (buffer[0] == '\0')
		{
			can_be_read = read(fd, buffer, BUFFER_SIZE);
			buffer[can_be_read] = '\0';
		}
		len = 0;
		while (buffer[len] && buffer[len] != '\n')
			len++;
		if (buffer[len] == '\n')
			return (read_line(line, buffer, ++loop, len));
		if (read_line(line, buffer, ++loop, len) == -1)
			return (-1);
	}
	return (0);
}
