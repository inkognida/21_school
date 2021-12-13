/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:15:34 by hardella          #+#    #+#             */
/*   Updated: 2021/12/13 14:39:56 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	apply_max(t_stack **stack_a, t_stack **stack_b, int max)
{
	if (max == 0)
		pb(stack_a, stack_b, 1);
	else if (max == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	else if (max == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	else if (max == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	else if (max == 4)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
}

void	apply_min(t_stack **stack_a, t_stack **stack_b, int min)
{
	if (min == 0)
		pb(stack_a, stack_b, 1);
	if (min == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	if (min == 2)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	if (min == 3)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	apply_max(stack_a, stack_b, get_max(stack_a));
	apply_min(stack_a, stack_b, get_min(stack_a));
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
	ra(stack_a, 1);
}
