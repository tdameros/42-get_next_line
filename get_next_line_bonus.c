/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:13:57 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/10 23:45:40 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE];
	char		*line;
	char		*line_temp;
	int			is_line;

	if (fd < 0)
		return (NULL);
	if (is_empty_buf(buf[fd], BUFFER_SIZE)
		&& read(fd, buf[fd], BUFFER_SIZE) <= 0)
		return (NULL);
	line = extract_line_in_buf(buf[fd], BUFFER_SIZE, &is_line);
	if (line == NULL)
		return (NULL);
	while (is_line == 0)
	{
		if (read(fd, buf[fd], BUFFER_SIZE) == 0)
			return (line);
		line_temp = extract_line_in_buf(buf[fd], BUFFER_SIZE, &is_line);
		if (line_temp == NULL)
			return (free_ret_null(line, NULL));
		line = strjoin_free(line, line_temp);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

int	is_empty_buf(char *buf, size_t buf_size)
{
	size_t	index;

	index = 0;
	while (index < buf_size)
	{
		if (buf[index] != '\0')
			return (0);
		index++;
	}
	return (1);
}

char	*extract_line_in_buf(char *buf, size_t buf_size, int *is_line)
{
	char	*line;
	size_t	start;
	size_t	len;

	start = line_start_in_buf(buf, buf_size);
	len = line_len_in_buf(buf, buf_size, start);
	line = subline_in_buf(buf, start, len);
	if (line == NULL)
		return (NULL);
	*is_line = line[len - 1] == '\n';
	return (line);
}

char	*free_ret_null(void *ptr1, void *ptr2)
{
	if (ptr1 != NULL)
		free(ptr1);
	if (ptr2 != NULL)
		free(ptr2);
	return (NULL);
}
