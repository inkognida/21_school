/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:35:48 by hardella          #+#    #+#             */
/*   Updated: 2021/12/10 16:06:21 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error_input(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_input_empty(int *stack_a, int *stack_b)
{
	free(stack_a);
	free(stack_b);
	exit(1);
}

void	error_input_malloc(int *stack_a, int *stack_b)
{
	if (!(stack_b) || !(stack_a))
	{
		write(2, "Malloc error\n", ft_strlen("Malloc error\n"));
		exit(1);
	}
	return ;
}
