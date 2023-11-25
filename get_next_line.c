/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:48:06 by rpisoner          #+#    #+#             */
/*   Updated: 2023/11/25 20:16:50 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*is_line(char *buffer, size_t i)
{
	size_t	j;
	char	*line;

	j = 0;
	line = (char *)malloc((BUFFER_SIZE - (i + 1)) * sizeof(char));
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	size_t		i;

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n')
		i++;
	buffer = is_line(buffer, i);
	return (buffer);
}

int	main(void)
{
	int		file;
	char	*next;
	int		i;

	i = 0;
	file = open("pruebas.txt", O_RDWR);
	next = get_next_line(file);
	printf("%s", next);
}
