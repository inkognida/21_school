/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:35:48 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 19:30:06 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack_a;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

void	error_input(t_stack **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_input_empty(t_stack **stack_a)
{
	free_stack(stack_a);
	exit(1);
}

void	exit_list(t_stack **stack_a)
{
	free_stack(stack_a);
	exit(1);
}
