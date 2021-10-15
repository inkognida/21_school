/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:43:06 by hardella          #+#    #+#             */
/*   Updated: 2021/10/15 20:11:43 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*free_null(char **line)
{
	free(*line);
	return (NULL);
}

static int	get_read(int fd, char *buff)
{
	if (ft_strlen(buff))
		return (ft_strlen(buff));
	else
		return (read(fd, buff, BUFFER_SIZE));
}

static char	*final_line(char **line, char *buff)
{
	if (ft_strlen(*line) != 0)
	{
		buff[0] = '\0';
		return (*line);
	}
	*line = ft_strjoin(*line, buff);
	buff[0] = '\0';
	return (*line);
}

static char	*gnl_main(int fd, char *buff, char *line)
{
	int		r_b;
	char	*g_n;

	r_b = get_read(fd, buff);
	if (r_b <= 0)
		return (free_null(&line));
	while (r_b)
	{
		buff[r_b] = '\0';
		g_n = ft_strchr(buff, '\n');
		if (g_n)
		{
			*g_n = '\0';
			line = ft_strjoin(line, buff);
			line = ft_strjoin(line, "\n");
			ft_strlcpy(buff, ++g_n, BUFFER_SIZE);
			return (line);
		}
		line = ft_strjoin(line, buff);
		r_b = read(fd, buff, BUFFER_SIZE);
	}
	return (final_line(&line, buff));
}

char	*get_next_line(int fd)
{	
	char		*line;
	static char	buff[BUFFER_SIZE + 1];

	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_null(&line));
	line = gnl_main(fd, buff, line);
	return (line);
}

// #include <string.h>
// #include <stdio.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	//char *r;
// 	int fd = open("file.txt", O_RDONLY);
// 	//r = get_next_line(fd);
// 	char *s = get_next_line(fd);
// 	char *q = get_next_line(fd);
// 	printf("%s\n", s);
// 	printf("%s\n", q);
// 	// while (s)
// 	// {
// 	// 	printf("%s\n", s);
// 	// 	s = get_next_line(fd);
// 	// }
// 	free(s);
// 	free(q);
// }
