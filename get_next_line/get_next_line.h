/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:46:31 by acerrah           #+#    #+#             */
/*   Updated: 2023/01/04 17:35:40 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_2(const char *str);
char	*ft_strdup(const char *s1);
char	*get_left(char *left);
char	*get_line(char *buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_get_next_line(char *s1, char const *s2);
char	*get_buffer(int fd, char *left_str);

#endif
