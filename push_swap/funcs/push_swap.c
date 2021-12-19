/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:45:24 by hardella          #+#    #+#             */
/*   Updated: 2021/12/19 13:53:31 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	display(t_stack *stack_a)
{
	while (stack_a)
	{
		printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	get_stack(&stack_a, argv, argc);
	if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 6)
		sort_five(&stack_a, &stack_b);
	else
		sort_one(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
