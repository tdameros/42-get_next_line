/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:13:57 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/21 01:03:56 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_empty_buff(char *buf)
{
	size_t	index;

	index = 0;
	while (index < BUFFER_SIZE)
	{
		if (buf[index] != '\0')
			return (0);
		index++;
	}
	return (1);
}

char	*extract_line(char *buf, size_t buf_size, int *is_line)
{
	char	*substr;
	size_t	start;
	size_t	len;

	start = ft_start_stri(buf, buf_size);
	len = ft_len_stri(buf, start, buf_size);
	substr = ft_substr(buf, start, len);
	if (substr == NULL)
		return (NULL);
	*is_line = substr[len - 1] == '\n';
	return (substr);
}

char	*free_ret_null(void *ptr1, void *ptr2)
{
	if (ptr1 != NULL)
		free(ptr1);
	if (ptr2 != NULL)
		free(ptr2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE];
	int			is_line;
	char		*line;
	char		*line_temp;

	if (fd < 0 || fd >= 1024)
		return (NULL);
	if (ft_is_empty_buff(buf[fd]) && read(fd, buf[fd], BUFFER_SIZE) <= 0)
		return (NULL);
	line = extract_line(buf[fd], BUFFER_SIZE, &is_line);
	if (line == NULL)
		return (NULL);
	while (is_line == 0)
	{
		if (read(fd, buf[fd], BUFFER_SIZE) == 0)
			return (line);
		line_temp = extract_line(buf[fd], BUFFER_SIZE, &is_line);
		if (line_temp == NULL)
			return (free_ret_null(line, NULL));
		line = ft_strjoin(line, line_temp);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
