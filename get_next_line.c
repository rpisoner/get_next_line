/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:48:06 by rpisoner          #+#    #+#             */
/*   Updated: 2023/12/04 20:52:16 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remainings(char *leftovers, size_t i)
{
	char	*remainings;
	size_t	j;

	j = 0;
	i += 1;
	remainings = (char *)malloc((BUFFER_SIZE - i + 1) * sizeof(char));
	while (leftovers[i])
	{
		remainings[j] = leftovers[i];
		j++;
		i++;
	}
	return (remainings);
}

char	*is_line(char *buffer, size_t i)
{
	size_t		j;
	char		*line;

	j = 0;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i && buffer[j])
	{
		line[j] = buffer[j];
		j++;
	}
	return (line);
}

char	*ft_readfile(char *buffer, int fd)
{
	size_t		i;
	size_t		o_read;
	char		*line;
	static char	*leftovers;
	char		*tmp;

	o_read = read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	i = 0;
	if (!leftovers)
	{
		leftovers = malloc((BUFFER_SIZE + 1) * sizeof(char));
		leftovers[BUFFER_SIZE] = '\0';
		leftovers = ft_memcpy(leftovers, buffer, BUFFER_SIZE);
	}
	while (o_read)
	{
		tmp = leftovers;
		if (!leftovers[i])
		{
			o_read = read(fd, buffer, BUFFER_SIZE);
			if (o_read)
			{
				while (o_read < BUFFER_SIZE)
					buffer[o_read++] = '\0';
				leftovers = ft_strjoin(tmp, buffer);
			}
			else
				return (leftovers);
			free(tmp);
		}
		while (leftovers[i])
		{
			if (leftovers[i] == '\n')
			{
				line = is_line(leftovers, i);
				tmp = leftovers;
				leftovers = remainings(leftovers, i);
				free (tmp);
				return (line);
			}
			i++;
		}
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	return (ft_readfile(buffer, fd));
}

int	main(void)
{
	int		file;
	char	*next;

	file = open("pruebas.txt", O_RDWR);
	next = get_next_line(file);
	printf("%s", next);
	return (0);
}

//TODOS
// CUANDO LEE UN ARCHIVO QUE NO TIENE SALTO DE LÍNEA, DEVUELVE LA LÍNEA, REPETIDO EL FINAL BUFFERSIZE VECES
// SEGMENTATION FAULT AL TRATAR DE LEER UN SALTO DE LÍNEA