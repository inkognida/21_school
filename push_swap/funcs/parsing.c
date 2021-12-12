/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:44:03 by hardella          #+#    #+#             */
/*   Updated: 2021/12/12 18:45:58 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

long int	atoi_ps(char *str)
{
	long int	i;
	long int	sign;
	long int	r;

	sign = 1;
	r = 0;
	i = 0;
	while (str[i] == ' ' || ((str[i] >= 9 && str[i] <= 13) && str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (sign * r);
}

int	not_in(t_stack *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->num == value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_sort(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->num > stack_a->next->num)
			return (0);
		else
			stack_a = stack_a->next;
	}
	return (1);
}

void	get_stack(t_stack **stack_a, char **argv, int argc)
{
	int					i;
	long int			n;

	if (argc <= 2)
		error_input_empty(stack_a);
	i = 1;
	while (i < argc)
	{
		if (ft_isint(argv[i]) && argv[i][0] == '0' && not_in(*stack_a, 0) && \
			ft_strlen(argv[i]) == 1)
		{
			push_back(stack_a, 0);
			i++;
			continue ;
		}
		n = atoi_ps(argv[i]);
		if (n && min_max(n) && not_in(*stack_a, n) && ft_isint(argv[i]))
			push_back(stack_a, n);
		else
			error_input(stack_a);
		i++;
	}
	if (check_sort(*stack_a) == 1)
		error_input_empty(stack_a);
}
