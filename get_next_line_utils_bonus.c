/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajaite <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:20 by sajaite           #+#    #+#             */
/*   Updated: 2023/11/16 20:10:44 by sajaite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, int *n)
{
	char	*join;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (0);
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	if (s2)
	{
		*n = pos_newline(s2);
		while (*s2)
			join[i++] = *s2++;
	}
	join[i] = 0;
	free_ptr(&s1);
	return (join);
}

char	*extract_reste(char *ptr_line)
{
	int		pos_nl;
	char	*reste;
	int		len_reste;
	int		i;

	i = 0;
	pos_nl = pos_newline(ptr_line) + 1;
	if (pos_nl == 0)
		return (0);
	len_reste = ft_strlen(ptr_line) - pos_nl;
	if (len_reste == 0)
		return (0);
	reste = malloc(len_reste + 1);
	ptr_line = ptr_line + pos_nl;
	while (i < len_reste)
	{
		reste[i] = ptr_line[i];
		i++;
	}
	reste[i] = '\0';
	return (reste);
}

char	*extract_line(char *s, int len)
{
	int		index;
	char	*substring;
	int		s_len;

	if (!s)
		return (0);
	s_len = len;
	if (s_len <= 0)
		s_len = ft_strlen(s);
	index = 0;
	substring = malloc(sizeof(char) * (s_len + 1));
	if (!substring)
		return (0);
	while (s[index] && index < s_len)
	{
		substring[index] = s[index];
		index++;
	}
	substring[index] = 0;
	return (substring);
}
