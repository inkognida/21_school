/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:45:24 by hardella          #+#    #+#             */
/*   Updated: 2021/12/10 17:33:11 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = (int *)malloc(sizeof(int) * argc);
	stack_b = (int *)malloc(sizeof(int) * argc);
	error_input_malloc(stack_a, stack_b);
	stack_a = pars_values(argv, argc, stack_a, stack_b);
	
	// for (int i = 0; i < argc - 1; i++)
		// printf("%d\n", stack_a[i]);
	ra(&stack_a, argc);
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", stack_a[i]);
	// if (argc - 1 == 3)
	// 	smallest_sort(stack_a, stack_b);
	// if (argc - 1 == 5)
	// 	second_sort(stack_a, stack_b);
	// if (argc - 1 <= 100)
	// 	big_sort(stack_a, stack_b);
	// if (argc - 1 > 100 && argc - 1 <= 500)
	// 	huge_sort(stack_a, stack_b);
	// else
	// 	return (write(2, "aboba\n", ft_strlen("aboba\n")));
}
