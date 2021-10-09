#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	dest = new;
	while (lst->next)
	{
		new->next = ft_lstnew((f(lst->next->content)));
		if (new->next == NULL)
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (dest);
}
