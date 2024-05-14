/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajaite <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:29:59 by sajaite           #+#    #+#             */
/*   Updated: 2023/11/16 20:01:22 by sajaite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *get_next_line(int fd)
{
	int rd;
	char *line;
	static char buf[BUFFER_SIZE + 1];
	char *newline = 0;
	int len_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
	{
		buf[0] = 0;
		return (0);
	}
	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd] = 0;
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (newline)
	{
		len_line = newline - line;
		ft_strcpy(buf, newline);
	}
	else
	{
		len_line = ft_strlen(line);
		buf[0] = 0;
	}
	line[len_line] = 0;
	return (line);
} 

/*
 int main()
 {	

 	int fd;
 	char	*line;
	int i = 0;

 	fd = open("test.txt", O_RDONLY);
 	while (i>=0)
 	{
 		line = get_next_line(fd);
 		if (line == NULL)
 			break;
 		printf("%p", line);
 		free (line);
		i++;
		system("leaks a.out");
 	}
 	close(fd);
 	return (0);
 }*/