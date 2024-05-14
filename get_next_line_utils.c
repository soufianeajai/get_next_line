/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajaite <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:30:17 by sajaite           #+#    #+#             */
/*   Updated: 2023/11/16 20:10:23 by sajaite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_strcpy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = 0;
}

char *ft_strdup(char *str)
{
	size_t len = ft_strlen(str);
	char *line = malloc(len + 1);
	if (!line)
		return (0);
	ft_strcpy(line, str);
	return (line);
}

char *ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			str++;
			return (str);
		}
		str++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	size_t len1 = ft_strlen(s1);
	size_t len2 = ft_strlen(s2);
	char *line = malloc(len1 + len2 + 1);
	if (!line)
		return (0);
	ft_strcpy(line, s1);
	ft_strcpy(line + len1, s2);
	free(s1);
	s1 = 0;
	return (line);
}