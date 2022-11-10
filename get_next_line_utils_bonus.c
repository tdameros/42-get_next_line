/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:06:16 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/10 23:46:31 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	line_start_in_buf(char *buf, size_t buf_size)
{
	size_t	index;

	index = 0;
	while (buf[index] == 0 && index < buf_size)
		index++;
	return (index);
}

size_t	line_len_in_buf(char *buf, size_t buf_size, size_t start)
{
	size_t	len;

	len = 0;
	while (start < buf_size && buf[start] != 0 && buf[start] != '\n')
	{
		start++;
		len++;
	}
	if (start < buf_size && buf[start] == '\n')
		len++;
	return (len);
}

char	*subline_in_buf(char *buf, size_t start, size_t len)
{
	size_t	index_substr;
	char	*substr;

	index_substr = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (index_substr < len)
	{
		substr[index_substr] = buf[start];
		buf[start] = 0;
		start++;
		index_substr++;
	}
	substr[index_substr] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	char	*end_ptr;

	end_ptr = (char *) s;
	while (*end_ptr != '\0')
		end_ptr++;
	return (end_ptr - s);
}

char	*strjoin_free(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;
	char	*str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	index = -1;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
		return (free_ret_null(s1, s2));
	while (++index < len_s1)
		str[index] = s1[index];
	index = -1;
	while (++index < len_s2)
		str[len_s1 + index] = s2[index];
	str[len_s1 + index] = '\0';
	free(s1);
	free(s2);
	return (str);
}
