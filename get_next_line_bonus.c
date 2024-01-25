/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajaite <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:56:22 by sajaite           #+#    #+#             */
/*   Updated: 2023/11/16 20:01:58 by sajaite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	pos_newline(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*read_in_line(int fd, char *line)
{
	int		rd;
	int		n;
	char	*buf;

	rd = BUFFER_SIZE;
	n = -1;
	while (n == -1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (0);
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd <= 0)
		{
			free_ptr(&buf);
			break ;
		}
		buf[rd] = '\0';
		line = ft_strjoin(line, buf, &n);
		free_ptr(&buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line1;
	char		*line;
	int			readed;
	static char	*reste = 0;

	line1 = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line1, 0) < 0)
	{
		free_ptr(&reste);
		return (NULL);
	}
	if (reste)
	{
		line1 = ft_strjoin(0, reste, &readed);
		free_ptr(&reste);
	}
	line1 = read_in_line(fd, line1);
	if (!line1)
		return (0);
	reste = extract_reste(line1);
	line = extract_line(line1, (pos_newline(line1) + 1));
	free_ptr(&line1);
	return (line);
}

void	free_ptr(char **str)
{
	free (*str);
	*str = 0;
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
