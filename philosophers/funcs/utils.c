/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:20:13 by hardella          #+#    #+#             */
/*   Updated: 2022/01/20 22:23:58 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	full_free(t_ph *philos, t_fork *forks, t_p *args)
{
	int	i;

	i = 0;
	while (i < args->nb)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&args->print);
	free(philos);
	free(forks);
	return (0);
}

int	error_output(t_ph *phs, t_fork *forks, int flag)
{
	if (flag == 4 || flag == 5)
	{
		free(phs);
		free(forks);
		write(2, "Pthread init error\n", ft_strlen("Pthread init error\n"));
	}
	else
	{
		(void)forks;
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
	printf("%lu %d %s\n", get_time() - arg->start_time, id, s);
	pthread_mutex_unlock(&arg->print);
}

t_ph	*spawn(t_p *arg, t_fork *forks)
{
	t_ph	*phs;
	int		i;

	phs = malloc(sizeof(t_p) * arg->nb);
	if (!phs)
		return (NULL);
	i = 0;
	while (i < arg->nb)
		if (pthread_mutex_init(&forks[i++].mutex, NULL))
			error_output(phs, forks, MUTEX_INIT_ERROR);
	i = 0;
	get_forks(phs, arg, forks);
	arg->start_time = get_time();
	while (i < arg->nb)
	{
		if (pthread_create(&phs[i].tid, NULL, &control, &phs[i]))
			error_output(phs, forks, PTHREAD_ERROR);
		usleep(100);
		i++;
	}
	i = 0;
	while (i < arg->nb)
		pthread_detach(phs[i++].tid);
	return (phs);
}
