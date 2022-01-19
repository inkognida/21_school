/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:18:16 by hardella          #+#    #+#             */
/*   Updated: 2022/01/19 23:49:46 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	*game(void *p)
{
	t_ph		*philo;

	philo = (t_ph *)p;
	philo->die_time = philo->arg->start + philo->arg->dt;
	while (1)
	{
		print(THINK, philo->arg, philo->id);
		pthread_mutex_lock(&philo->min->mutex);
		print(FORK, philo->arg, philo->id);
		pthread_mutex_lock(&philo->max->mutex);
		print(FORK, philo->arg, philo->id);
		print(EAT, philo->arg, philo->id);
		usleep(philo->arg->et * 1000);
		philo->die_time = get_time() + philo->arg->dt;
		philo->must_eat += 1;
		pthread_mutex_unlock(&philo->max->mutex);
		pthread_mutex_unlock(&philo->min->mutex);
		print(SLEEP, philo->arg, philo->id);
		usleep(philo->arg->st * 1000);
	}
}

static int	health(t_ph *philos, t_p *args, int count, t_fork *forks)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < count)
		{
			philos[i].indx = i;
			if (get_time() >= philos[i].die_time + 5)
			{
				philo_exit(philos, args, DED, forks);
				return (0);
			}
			if (philos[i].must_eat == args->met)
			{
				philo_exit(philos, args, MET, forks);
				return (0);
			}
			i++;
		}
	}
}

static void	get_forks(t_ph *phs, t_p *arg, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < arg->nb)
	{
		phs[i].id = i + 1;
		phs[i].arg = arg;
		phs[i].must_eat = 0;
		phs[i].min = &forks[i];
		phs[i].max = &forks[(i + 1) % arg->nb];
		if (i > (i + 1) % arg->nb)
		{
			phs[i].max = &forks[i];
			phs[i].min = &forks[(i + 1) % arg->nb];
		}
		i++;
	}
}

static t_ph	*spawn(t_p *arg, t_fork *forks)
{
	t_ph	*phs;
	int		i;

	phs = malloc(sizeof(t_p) * arg->nb);
	if (!phs)
		return (NULL);
	i = 0;
	while (i < arg->nb)
	{
		if (pthread_mutex_init(&forks[i++].mutex, NULL))
			error_output(phs, MUTEX_ERROR);
	}
	i = 0;
	get_forks(phs, arg, forks);
	while (i < arg->nb)
	{
		if (pthread_create(&phs[i].tid, NULL, game, &phs[i]))
			error_output(phs, PTHREAD_ERROR);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < arg->nb)
		pthread_detach(phs[i++].tid);
	return (phs);
}

int	main(int argc, char **argv)
{
	t_p		args;
	t_ph	*philos;
	t_fork	*forks;

	args.met = -1;
	args.start = get_time();
	if ((argc == 5 || argc == 6) && pars_init(argc, argv, &args))
	{
		if (pthread_mutex_init(&args.print, NULL))
			return (error_output(NULL, MUTEX_ERROR));
		forks = malloc(sizeof(t_fork *) * args.nb);
		if (!(forks))
			return (error_output(NULL, MALLOC_ERROR));
		philos = spawn(&args, forks);
		if (!(philos))
			return (error_output(philos, MALLOC_ERROR));
		return (health(philos, &args, args.nb, forks));
	}
	else
		return (error_output(NULL, PARS_ERROR));
}
