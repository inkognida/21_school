/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:37:04 by hardella          #+#    #+#             */
/*   Updated: 2021/12/10 17:29:37 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sa(int **stack_a)
{
	int	tmp;

	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
}

void	sb(int **stack_b)
{
	int	tmp;

	tmp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
}

void	ss(int **stack_a, int **stack_b)
{
	int	tmp;
	int	tmp1;

	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
	tmp1 = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
}

void	ra(int **stack_a, int argc)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = (*stack_a)[0];
	while (argc - 2 > 0)
	{
		(*stack_a)[i] = (*stack_a)[i + 1];
		i++;
		argc--;
	}
	(*stack_a)[argc - 1] = tmp;
}
