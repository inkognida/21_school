/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:49:36 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 18:07:46 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int f)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_b) > 0)
	{
		push_front(stack_a, (*stack_b)->num);
		tmp = (*stack_b)->next;
		free(*(stack_b));
		(*stack_b) = tmp;
	}
	if (f)
		write(1, "pa\n", ft_strlen("pa\n"));
}

void	pb(t_stack **stack_a, t_stack **stack_b, int f)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_a) > 0)
	{
		push_front(stack_b, (*stack_a)->num);
		tmp = (*stack_a)->next;
		free(*(stack_a));
		(*stack_a) = tmp;
	}
	if (f)
		write(1, "pb\n", ft_strlen("pa\n"));
}
