/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:03:59 by hardella          #+#    #+#             */
/*   Updated: 2021/12/13 11:12:40 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->num;
	n2 = (*stack_a)->next->num;
	n3 = (*stack_a)->next->next->num;
	if (n1 > n2 && n2 > n3)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(stack_a, 1);
	else if (n1 > n2 && n2 < n3 && n3 > n1)
		sa(stack_a, 1);
	else if (n1 < n2 && n2 > n3 && n2 > n1)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (n1 > n2 && n2 < n3)
		ra(stack_a, 1);
}
