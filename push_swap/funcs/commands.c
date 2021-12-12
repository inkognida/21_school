/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:29:48 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 18:07:18 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sa(t_stack **stack_a, int f)
{
	int	temp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		temp = (*stack_a)->num;
		(*stack_a)->num = (*stack_a)->next->num;
		(*stack_a)->next->num = temp;
	}
	if (f)
		write(1, "sa\n", ft_strlen("sa\n"));
}

void	sb(t_stack	**stack_b, int f)
{
	int	temp;

	if (ft_lstsize(*stack_b) >= 2)
	{
		temp = (*stack_b)->num;
		(*stack_b)->num = (*stack_b)->next->num;
		(*stack_b)->next->num = temp;
	}
	if (f)
		write(1, "sb\n", ft_strlen("sb\n"));
}

void	ss(t_stack **stack_a, t_stack **stack_b, int f)
{
	if (f)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		write(1, "ss\n", ft_strlen("ss\n"));
	}
}

void	ra(t_stack **stack_a, int f)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		push_back(stack_a, (*stack_a)->num);
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	if (f)
		write(1, "ra\n", ft_strlen("ra\n"));
}

void	rb(t_stack	**stack_b, int f)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_b) > 1)
	{
		push_back(stack_b, (*stack_b)->num);
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	if (f)
		write(1, "rb\n", ft_strlen("rb\n"));
}
