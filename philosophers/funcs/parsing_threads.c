/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:09:25 by hardella          #+#    #+#             */
/*   Updated: 2022/01/20 22:15:23 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	exc(long int value, int f)
{
	if (f == 1 && value > 0 && value <= 200)
		return (1);
	else if (f == 2 && value >= 60)
		return (1);
	else if (f == 3 && value >= 60)
		return (1);
	else if (f == 4 && value >= 60)
		return (1);
	else if (f == 5 && value > 0)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str, int f)
{
	long int	i;
	long int	sign;
	long int	r;

	sign = 1;
	r = 0;
	i = 0;
	while (str[i])
		if (str[i] > '9' || str[i++] < '0')
			return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	if (!exc(sign * r, f) && (sign * r < MAX) && (sign * r > MIN))
		return (0);
	return (sign * r);
}

void	accept(int value, t_p *arg, int index)
{
	if (index == 1)
		arg->nb = value;
	else if (index == 2)
		arg->dt = value;
	else if (index == 3)
		arg->et = value;
	else if (index == 4)
		arg->st = value;
	else if (index == 5)
		arg->met = value;
}

int	pars_init(int argc, char **argv, t_p *arg)
{
	int	i;
	int	v;

	i = 1;
	while (i < argc)
	{
		v = ft_atoi(argv[i], i);
		if (v)
			accept(v, arg, i);
		else
			return (0);
		i++;
	}
	return (1);
}
