/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:44:22 by rpisoner          #+#    #+#             */
/*   Updated: 2023/11/27 11:09:28 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size);
	if (ptr == 0)
		return (ptr);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (0);
	while ((char)s1[i] != '\0')
	{
		new[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j] != '\0')
	{
		new[i] = (char)s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
