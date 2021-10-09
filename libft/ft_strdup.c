#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		g;

	i = 0;
	g = 0;
	while (src[i])
		i++;
	copy = (char *) malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	while (src[g])
	{
		copy[g] = src[g];
		g++;
	}
	copy[g] = '\0';
	return (copy);
}
