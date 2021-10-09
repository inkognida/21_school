#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	if (n == 0)
		return ;
	temp = (char *)s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}
