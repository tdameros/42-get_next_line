/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:23:03 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/21 00:29:14 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_start_stri(char *buf, size_t buf_size);
size_t	ft_len_stri(char *buf, size_t start, size_t buf_size);

int		ft_is_empty_buff(char *buffer);
int		ft_is_line(char	*s);
char	*free_ret_null(void *ptr1, void *ptr2);
char	*get_next_line(int fd);

#endif
