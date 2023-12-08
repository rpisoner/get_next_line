/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:41:41 by rpisoner          #+#    #+#             */
/*   Updated: 2023/12/08 16:24:21 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*is_line(char *buffer, size_t *i)
{
	char		*line;

	while (buffer[*i] != '\n')
	{
		*i += 1;
	}
	line = ft_substr(buffer, 0, *i + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*remainings(char *leftovers, size_t *i)
{
	char	*remainings;
	size_t	j;
	size_t	aux;

	*i += 1;
	aux = *i;
	j = 0;
	while (leftovers[*i] != '\0')
		*i += 1;
	if (*i - aux <= 0)
		return (NULL);
	remainings = (char *)malloc((*i - aux) * sizeof(char));
	if (!remainings)
	{
		free(remainings);
		return (NULL);
	}
	while (aux <= *i)
	{
		remainings[j] = leftovers[aux];
		j++;
		aux++;
	}
	return (remainings);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*buffer;
	char		*tmp;
	char		*line;
	size_t		o_read;
	size_t		i;

	i = 0;
	line = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	if (!leftovers)
	{
		leftovers = (char *)malloc(BUFFER_SIZE * sizeof(char));
		o_read = read(fd, leftovers, BUFFER_SIZE);
	}
	while (leftovers[i])
	{
		tmp = leftovers;
		if (!ft_strchr(leftovers, '\n'))
		{
			o_read = read(fd, buffer, BUFFER_SIZE);
			if (o_read)
			{
				while (o_read < BUFFER_SIZE)
					buffer[o_read++] = '\0';
				leftovers = ft_strjoin(tmp, buffer);
				i += BUFFER_SIZE;
				free (tmp);
			}
			else
			{
				free (buffer);
				return (leftovers);
			}
		}
		else
		{
			line = is_line(leftovers, &i);
			leftovers = remainings(leftovers, &i);
			free (buffer);
			free (tmp);
			return (line);
		}
	}
	return (NULL);
}

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		file;
	char	*next;

	file = open("pruebas.txt", O_RDWR);
	next = get_next_line(file);
	while (next)
	{
		printf("%s", next);
		if (next)
			free(next);
		next = get_next_line(file);
	}
	exit(0);
	close(file);
	return (0);
}
