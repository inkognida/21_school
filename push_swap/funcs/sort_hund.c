/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:51:52 by hardella          #+#    #+#             */
/*   Updated: 2021/12/20 12:35:55 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	get_two_stacks(t_stack **stack_a, t_stack **stack_b, int median)
{
	while (ft_lstsize(*stack_a) > 2)
	{
		if ((*stack_a)->num == get_min_elem(stack_a) \
			|| (*stack_a)->num == get_max_elem(stack_a))
			ra(stack_a, 1);
		if ((*stack_a)->num < median)
			pb(stack_a, stack_b, 1);
		else
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
		}
	}
	if ((*stack_a)->num > (*stack_a)->next->num)
		ra(stack_a, 1);
}

int	moves_a(int num, t_stack *stack_a)
{
	int	c;
	int	size;
	int	min;

	size = ft_lstsize(stack_a);
	min = get_min_elem(&stack_a);
	c = 0;
	if (stack_a->num == min && num < stack_a->num)
		return (0);
	if (stack_a->num > num && ft_lstlast(stack_a)->num < num)
		return (0);
	while (stack_a->next)
	{
		c++;
		if ((num < stack_a->next->num && stack_a->next->num == min) || \
			(stack_a->num < num && (stack_a->next->num > num || \
			stack_a->next->num == min)))
			break ;
		stack_a = stack_a->next;
	}
	if (c > size / 2)
		return (-1 * (size - c));
	return (c);
}

int	moves_b(int num, t_stack *stack_b)
{
	int	size;
	int	c;

	c = 0;
	size = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->num == num)
			break ;
		stack_b = stack_b->next;
		c++;
	}
	if (c > size / 2)
		return (-1 * (size - c));
	return (c);
}

void	total_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	c;
	int	size;
	int	moves_sa;

	size = ft_lstsize(stack_b);
	c = 0;
	while (stack_b)
	{
		moves_sa = moves_a(stack_b->num, stack_a);
		if (moves_sa < 0)
			moves_sa *= -1;
		if (c < size / 2)
			stack_b->moves = c + moves_sa;
		else
			stack_b->moves = (size - c) + moves_sa;
		c++;
		stack_b = stack_b->next;
	}
}

void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	get_two_stacks(stack_a, stack_b, get_median(*stack_a));
	while (ft_lstsize(*stack_b) > 0)
	{
		total_moves(*stack_a, *stack_b);
		rotate(stack_a, stack_b);
	}
	a_rotate(stack_a);
}
