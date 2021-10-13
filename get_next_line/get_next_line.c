/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:24:42 by hardella          #+#    #+#             */
/*   Updated: 2021/10/13 21:35:19 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h> // need to delete

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*join(char *buffer, char *line)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	//printf("%s\n", buffer);
	if (!(buffer))
		return (NULL);
	//printf("%s %s %d %d\n", line, buffer, ft_strlen(buffer), ft_strlen(line));
	str = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + \
			ft_strlen(line) + 1));
	if (!(str))
		return (NULL);
	while (line[++i])
		str[i] = line[i];
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_line(int fd, char *line)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buffer))
		return (NULL);
	while (r > 0 && (ft_strchr(line, '\n')))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		line = join(buffer, line);
		if (!(line))
			return (NULL);
	}
	free(buffer);
	return (line);
}

// static char	*form_line(char *line)
// {
	
// }

char	*get_next_line(int fd)
{
	//char		*line_form;
	static char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line);
	if (!(line))
		return (NULL);
	// line_form = form_line(line);
	//line = get_next_new_line(line);
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
