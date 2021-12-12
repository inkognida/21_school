/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:45:24 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 20:32:43 by hardella         ###   ########.fr       */
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
	if (argc == 6)
		sort_five(&stack_a, &stack_b);
	// sa(&stack_a, 1);
	// pb(&stack_a, &stack_b, 1);
	// pb(&stack_a, &stack_b, 1);
	// pb(&stack_a, &stack_b, 1);
	// ra(&stack_a, 1);
	// rb(&stack_b, 1);
	// rra(&stack_a, 1);
	// rrb(&stack_b, 1);
	// sa(&stack_a, 1);
	// pa(&stack_a, &stack_b, 1);
	// pa(&stack_a, &stack_b, 1);
	// pa(&stack_a, &stack_b, 1);

	display(stack_a);


	//fix leaks
	// free_stack(&stack_a);
	// free_stack(&stack_b);
}
