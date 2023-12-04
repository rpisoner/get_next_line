/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:41:03 by rpisoner          #+#    #+#             */
/*   Updated: 2023/12/04 17:27:43 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
//FUNCIONES EN GET_NEXT_LINE
char	*get_next_line(int fd);
char	*check_if_line(char *buffer, size_t i, int fd);
char	*not_line(char *buffer, size_t i, int fd);
char	*leftovers(char *buffer, size_t i, int fd);
//FUNCIONES EN GET_NEXT_LINE_UTILS
void	*ft_calloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
