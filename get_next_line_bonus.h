/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajaite <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:59:54 by sajaite           #+#    #+#             */
/*   Updated: 2023/11/16 19:07:10 by sajaite          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*read_in_line(int fd, char *line);
int		pos_newline(char *str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int *n);
char	*extract_line(char *s, int len);
char	*extract_reste(char *line);
void	free_ptr(char **str);
#endif
