/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:48:06 by rpisoner          #+#    #+#             */
/*   Updated: 2023/11/27 14:12:12 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*not_line(char *buffer, size_t i, int fd)
{
	char	*old;
	char	*new;

	old = ft_strjoin("\0", buffer);
	read(fd, buffer, BUFFER_SIZE);
	new = strjoin(old, buffer);
	while (new[i] != '\n' && new[i])
		i++;
	if (new[i] == '\n')
	{
		leftovers(buffer, i, fd);
		return (check_if_line(new, i, fd));
	}
	else
		not_line(new, i, fd);
}

char	*check_leftovers(char *buffer, size_t i, int fd)
{
	static char	*remaining;
	char		*rests;
	size_t		j;

	j = 0;
	if (!remaining)
	{
		rests = ft_strjoin("\0", buffer + i);
		// read(fd, buffer, BUFFER_SIZE);
		// remaining = ft_strjoin(rests, buffer);
	}
	return (remaining);
}

char	*check_if_line(char *buffer, size_t i, int fd)
{
	size_t	j;
	char	*line;

	if (buffer[i] != '\n')
		return (not_line(buffer, i, fd));
	j = 0;
	line = (char *)malloc((BUFFER_SIZE - (i + 1)) * sizeof(char));
	if (i < BUFFER_SIZE - 2) //CONDICIÓN MALA, Si ha habido varios read, i es el índice de mezclar los restos y lo nuevo
	{
		//check_leftovers(buffer, i, fd);
	}
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
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	buffer = check_if_line(buffer, i, fd);
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

//TODOS
// GESTIÓN DE LOS RESTOS DEL BUFFER TRAS LEER UNA LÍNEA
// GESTIÓN DE ERRORES, LIBERACIÓN DE MEMORIA CUANDO FALLA ALGO