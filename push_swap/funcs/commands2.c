/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:29:48 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 17:49:24 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, int f)
{
	if (f)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		write(1, "rr\n", ft_strlen("rr\n"));
	}
}

void	rra(t_stack **stack_a, int f)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = *stack_a;
		prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		push_front(stack_a, tmp->num);
		free(prev->next);
		prev->next = NULL;
	}
	if (f)
		write(1, "rra\n", ft_strlen("rra\n"));
}

void	rrb(t_stack **stack_b, int f)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (ft_lstsize(*stack_b) > 1)
	{
		tmp = *stack_b;
		prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		push_front(stack_b, tmp->num);
		free(prev->next);
		prev->next = NULL;
	}
	if (f)
		write(1, "rrb\n", ft_strlen("rrb\n"));
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int f)
{
	if (f)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		write(1, "rrr\n", ft_strlen("rrr\n"));
	}
}
