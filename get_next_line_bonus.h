/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:23:03 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/10 23:44:16 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# if OPEN_MAX > 10000000
#  undef OPEN_MAX
#  define OPEN_MAX 10000000
# endif

size_t	ft_strlen(const char *s);
char	*strjoin_free(char *s1, char *s2);

char	*sub_line_in_buf(char *buf, size_t start, size_t len);
size_t	start_line_in_buf(char *buf, size_t buf_size);
size_t	len_line_in_buf(char *buf, size_t buf_size, size_t start);
char	*extract_line_in_buf(char *buf, size_t buf_size, int *is_line);
int		is_empty_buf(char *buf, size_t buf_size);

char	*free_ret_null(void *ptr1, void *ptr2);
char	*get_next_line(int fd);

#endif
