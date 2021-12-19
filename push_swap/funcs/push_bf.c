/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:48:44 by hardella          #+#    #+#             */
/*   Updated: 2021/12/19 23:05:26 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*create(t_stack **stack_a, int value)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		exit_list(stack_a);
	list->num = value;
	list->next = NULL;
	return (list);
}

void	push_back(t_stack **stack_a, int value)
{
	t_stack	*curr;

	curr = *stack_a;
	if (*stack_a == NULL)
		*stack_a = create(stack_a, value);
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = create(stack_a, value);
	}
}

void	push_front(t_stack **stack_a, int value)
{
	t_stack	*new;

	if (*stack_a == NULL)
		*stack_a = create(stack_a, value);
	else
	{
		new = create(stack_a, value);
		new->next = *stack_a;
		*stack_a = new;
	}
}
