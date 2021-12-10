#include <unistd.h>

int	check(char c, char *str, int index)
{
	int j = 0;

	while (j < index)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i;
	int	j;
	int c;

	i = 0;
	if (argc != 3)
		return (write(1, "\n", 1));
	while (argv[1][i])
	{
		if (check(argv[1][i], argv[1], i) == 0)
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[2][j] == argv[1][i])
				{
					write(1, &(argv[1][i]), 1);
					break;
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}