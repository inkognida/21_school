#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp;

	temp = c;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
		if (*s == '\0')
			return (NULL);
	}
	return (NULL);
}
