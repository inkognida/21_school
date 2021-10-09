#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	j;

	if (!(s) || !(f))
		return ;
	j = 0;
	while (s[j])
	{	
		f(j, s + j);
		j++;
	}
}
