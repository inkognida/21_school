/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:43:06 by hardella          #+#    #+#             */
/*   Updated: 2021/10/15 09:47:27 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>

static char	*gnl_main(int fd)
{
	char	*line;
	char	buff[BUFFER_SIZE + 1];
	int		bytes;
	char	*get_n;
	static char	*remain;
	int		flag;

	flag = 1;
	if (remain)
		line = ft_strdup(remain);
	else
		line = new_str(1);
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes && flag)
	{
		buff[bytes] = '\0';
		get_n = ft_strchr(buff, '\n');
		if (get_n)
		{
			*get_n = '\0';
			flag = 0;
			get_n++;
			remain = ft_strdup(get_n);
		}
		line = ft_strjoin(line, buff);
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{	
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gnl_main(fd);
	if (!(line))
		return (NULL);
	return (line);
}

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
