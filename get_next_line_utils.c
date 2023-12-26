/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:44:21 by rpisoner          #+#    #+#             */
/*   Updated: 2023/12/26 15:57:46 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
		return (NULL);
	if (s1)
	{
		while ((char)s1[i] != '\0')
		{
			new[i] = (char)s1[i];
			i++;
		}
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ((unsigned int)ft_strlen(s)) - start)
		len = ((unsigned int)ft_strlen(s)) - start;
	if (start > ft_strlen(s))
	{
		substr = "";
		return (substr);
	}
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (i < len && *(s + i) != '\0')
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i) != (char)c)
	{
		if (*(s + i) == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}
