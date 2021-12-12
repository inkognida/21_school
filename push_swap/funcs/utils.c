/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:41:04 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 18:38:43 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	min_max(long int a)
{
	if (a > 2147483647 || a < -2147483648)
		return (0);
	return (1);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!(lst))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
