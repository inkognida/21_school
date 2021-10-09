#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp;

	i = 0;
	temp = c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == temp)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
