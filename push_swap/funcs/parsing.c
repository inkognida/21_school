/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:44:03 by hardella          #+#    #+#             */
/*   Updated: 2021/12/10 16:11:05 by hardella         ###   ########.fr       */
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

int	not_in(int a, int *stack_a, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (stack_a[i] == a)
			return (0);
		i++;
	}
	return (1);
}

int	check_errors(int *stack_a, int argc)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (argc - 2 > 0)
	{
		if (stack_a[i] < stack_a[i + 1])
		{
			i++;
			argc--;
			continue ;
		}
		else
			flag = 1;
		i++;
		argc--;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	check_max_min(long int a)
{
	if (a > 2147483647 || a < -2147483648)
		return (0);
	return (1);
}

int	*pars_values(char **argv, int argc, int *stack_a, int *stack_b)
{
	int			i;
	long int	number;

	i = 0;
	number = 0;
	while (i < argc - 1)
	{
		if (argv[i + 1][0] == '0' && ft_strlen(argv[i + 1]) == 1 \
			&& not_in(0, stack_a, i))
		{
			stack_a[i++] = 0;
			continue ;
		}
		number = atoi_ps(argv[i + 1]);
		if (number && not_in(number, stack_a, i) && check_max_min(number))
			stack_a[i] = number;
		else
			error_input(stack_a, stack_b);
		i++;
	}
	if (!(check_errors(stack_a, argc)))
		error_input_empty(stack_a, stack_b);
	return (stack_a);
}
