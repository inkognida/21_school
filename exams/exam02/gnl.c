#include <unistd.h>

int get_next_line(char **line)
{
	int rd = 0, i = 0;
	char *buff = malloc(100000);
	*line = buff;
	
	while ((rd = read(0, &buff[i], 1)) > 0 && buff[i] != '\n')
		i++;
	buff[i] = '\0';
	return (rd);
}