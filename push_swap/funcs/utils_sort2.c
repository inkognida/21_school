/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:12:37 by hardella          #+#    #+#             */
/*   Updated: 2021/12/17 17:15:05 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	next_min(t_stack **stack_a, int min)
{
	t_stack	*tmp;
	int		n_min;

	n_min = get_max_elem(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->num > min && tmp->num < n_min)
			n_min = tmp->num;
		tmp = tmp->next;
	}
	return (n_min);
}

int	get_median(t_stack **stack_a)
{
	int	i;
	int	len;
	int	median;

	len = ft_lstsize(*stack_a);
	i = 0;
	while (i < len / 2)
	{
		median = next_min(stack_a, median);
		i++;
	}
	return (median);
}

void	rotate_cases(t_stack **stack_a, t_stack **stack_b, int *a, int *b)
{
	if (*a < 0 && *b < 0)
		while (*a < 5500 && *b < 5500 && (*a)++ < 0 && (*b)++ < 0)
			rrr(stack_a, stack_b, 1);
	else if (*a > 0 && *b > 0)
		while (*a > 5500 && *b > 5500 && (*a)-- > 0 && (*b)-- > 0)
			rr(stack_a, stack_b, 1);
	if (*a < 0)
		while ((*a)++)
			rra(stack_a, 1);
	else
		while ((*a)--)
			ra(stack_a, 1);
	if (*b < 0)
		while ((*b)++)
			rrb(stack_b, 1);
	else
		while ((*b)--)
			rb(stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	rotate(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	t_stack	*put_to;
	t_stack	*tmp;

	tmp = *stack_b;
	put_to = *stack_b;
	while (tmp)
	{
		if (tmp->moves < put_to->moves)
			put_to = tmp;
		tmp = tmp->next;
	}
	a = moves_a(put_to->num, *stack_a);
	b = moves_b(put_to->num, *stack_b);
	rotate_cases(stack_a, stack_b, &a, &b);
}

void	a_rotate(t_stack **stack_a)
{
	int		lp;
	t_stack	*tmp;

	lp = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->num == get_min_elem(stack_a))
			break ;
		tmp = tmp->next;
		lp++;
	}
	if (lp > ft_lstsize(*stack_a) / 2)
		lp = lp - ft_lstsize(*stack_a);
	if (lp > 0)
		while (lp--)
			ra(stack_a, 1);
	else
		while (lp++)
			rra(stack_a, 1);
}
