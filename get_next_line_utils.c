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

// char	*ft_strchr(char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 		{
// 			s++;
// 			return ((char *)s);
// 		}
// 		s++;
// 	}
// 	return (NULL);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i = 0;
	
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	ft_strcpy(char *dst, const char *src)
// {
// 	while (*src)	
// 		*dst++ = *src++;
// 	*dst = '\0';
// }

// char	*ft_strdup(const char *src)
// {
// 	size_t	len = ft_strlen(src) + 1;
// 	char	*dst = malloc(len);
	
// 	if (dst == NULL)
// 		return (NULL);
// 	ft_strcpy(dst, src);
// 	return (dst);
// }

// char	*ft_strjoin(char *s1, char const *s2)
// {
// 	size_t	s1_len = ft_strlen(s1);
// 	size_t	s2_len = ft_strlen(s2);
// 	char	*join = malloc((s1_len + s2_len + 1));

// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!join)
// 		return (NULL);
// 	ft_strcpy(join, s1);
// 	ft_strcpy((join + s1_len), s2);
// 	free(s1);
// 	s1 = 0;
// 	return (join);
// }







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