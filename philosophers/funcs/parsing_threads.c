/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:09:25 by hardella          #+#    #+#             */
/*   Updated: 2021/12/28 17:59:40 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long int	is_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] >= 48 && num[i] <= 57)
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	min_max(long int a)
{
	if (a > 2147483647 || a < -2147483648)
		return (0);
	return (1);
}

int	check_arg(char *num)
{
	if (is_num(num) && min_max(is_num(num)))
		return (is_num(num));
	else
		return (0);
}

void	accept(int f, int i)
{
	(void)f;
	(void)i;
}

void	pars_init(int argc, char **argv)
{
	int	i;
	int	f;

	i = 1;
	while (i < argc)
	{
		f = check_arg(argv[i]);
		if (f)
			accept(f, i);
		else
			error_input();
		i++;
	}
}
