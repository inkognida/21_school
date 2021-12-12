/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:15:34 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 20:35:20 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	help_sort(int n1, int n2, t_stack **stack_a, t_stack **stack_b)
{	
	int	c;
	int	n3;
	int	n4;
	int	n5;	

	c = 0;
	n3 = (*stack_a)->next->next->num;
	n4 = (*stack_a)->next->next->next->num;
	n5 = (*stack_a)->next->next->next->next->num;
	printf("%d %d %d %d %d\n", n1, n2, n3, n4, n5);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->num;
	n2 = (*stack_a)->next->num;
	help_sort(n1, n2, stack_a, stack_b);
}
