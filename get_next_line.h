/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:23:03 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/10 22:03:41 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*strjoin_free(char *s1, char *s2);

char	*subline_in_buf(char *buf, size_t start, size_t len);
size_t	line_start_in_buf(char *buf, size_t buf_size);
size_t	line_len_in_buf(char *buf, size_t buf_size, size_t start);
char	*extract_line_in_buf(char *buf, size_t buf_size, int *is_line);
int		is_empty_buf(char *buf, size_t buf_size);

char	*free_ret_null(void *ptr1, void *ptr2);
char	*get_next_line(int fd);

#endif
