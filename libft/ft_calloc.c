#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (count == 0 || size == 0)
		return (tmp);
	if (tmp)
	{
		ft_bzero(tmp, count * size);
		return (tmp);
	}
	return (NULL);
}
