/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:20:13 by hardella          #+#    #+#             */
/*   Updated: 2022/01/19 23:49:50 by hardella         ###   ########.fr       */
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

int	error_output(t_ph *phs, int flag)
{
	if (flag == 4)
	{
		free(phs);
		write(2, "Pthread init error\n", ft_strlen("Pthread init error\n"));
	}
	else
	{
		(void)phs;
		if (flag == 1)
			write(2, "Error input\n", ft_strlen("Error input\n"));
		else if (flag == 2)
			write(2, "Mutex init error\n", ft_strlen("Mutex init error\n"));
		else if (flag == 3)
			write(2, "Malloc init error\n", ft_strlen("Malloc init error\n"));
	}
	return (0);
}

unsigned long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print(char *s, t_p *arg, int id)
{
	pthread_mutex_lock(&arg->print);
	printf("%lu %d %s\n", get_time() - arg->start, id, s);
	pthread_mutex_unlock(&arg->print);
}

void	philo_exit(t_ph *philos, t_p *args, int f, t_fork *forks)
{
	int	i;

	i = 0;
	if (f == 1)
	{
		pthread_mutex_lock(&args->print);
		printf("%lu %s %d\n", get_time() - args->start, THINK, \
					philos[philos->indx].id);
	}
	else if (f == 2)
	{
		pthread_mutex_lock(&args->print);
		printf("%lu %s %d\n", get_time() - args->start, DIED, \
					philos[philos->indx].id);
	}
	while (i < philos[0].arg->nb)
		pthread_mutex_destroy(&forks[i++].mutex);
	pthread_mutex_destroy(&args->print);
	free(philos);
}
