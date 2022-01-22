/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:18:16 by hardella          #+#    #+#             */
/*   Updated: 2022/01/21 19:15:34 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	game(t_ph *philo)
{
	print(THINK, philo->arg, philo->id);
	pthread_mutex_lock(&philo->min->mutex);
	print(FORK, philo->arg, philo->id);
	pthread_mutex_lock(&philo->max->mutex);
	print(FORK, philo->arg, philo->id);
	philo->die_time = philo->die_time + philo->arg->dt;
	print(EAT, philo->arg, philo->id);
	usleep(philo->arg->et * 1000);
	pthread_mutex_unlock(&philo->max->mutex);
	pthread_mutex_unlock(&philo->min->mutex);
	print(SLEEP, philo->arg, philo->id);
	usleep(philo->arg->st * 1000);
}

void	*health(void *p)
{
	t_ph	*philo;

	philo = (t_ph *)p;
	while (1)
	{
		if (get_time() >= philo->die_time + 5)
		{
			print(DIED, philo->arg, philo->id);
			pthread_mutex_lock(&philo->arg->print);
			philo->arg->status = 1;
		}
		else if (philo->eat_max == 1)
		{
			philo->arg->eat_nb++;
			break ;
		}
	}
	return (NULL);
}

void	*control(void *p)
{
	int			i;
	t_ph		*philo;
	pthread_t	h;

	philo = (t_ph *)p;
	philo->eat_max = 0;
	i = 0;
	philo->die_time = philo->arg->start_time + philo->arg->dt;
	pthread_create(&h, NULL, health, philo);
	pthread_detach(h);
	while (i < philo->arg->met || !(philo->arg->met))
	{
		game(philo);
		i++;
		if (i == philo->arg->met)
			print(THINK, philo->arg, philo->id);
	}
	philo->eat_max = 1;
	return (NULL);
}

void	get_forks(t_ph *phs, t_p *arg, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < arg->nb)
	{
		phs[i].id = i + 1;
		phs[i].arg = arg;
		phs[i].min = &forks[i];
		phs[i].max = &forks[(i + 1) % arg->nb];
		if (i > ((i + 1) % arg->nb))
		{
			phs[i].max = &forks[i];
			phs[i].min = &forks[(i + 1) % arg->nb];
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_p		args;
	t_ph	*philos;
	t_fork	*forks;
	int		i;

	i = 0;
	args.eat_nb = 0;
	args.status = 0;
	if (!((argc == 5 || argc == 6) && pars_init(argc, argv, &args)))
		return (error_output(NULL, NULL, PARS_ERROR));
	if (pthread_mutex_init(&args.print, NULL))
		return (error_output(NULL, NULL, MUTEX_ERROR));
	forks = malloc(sizeof(t_fork) * args.nb);
	if (!(forks))
		return (error_output(NULL, NULL, MALLOC_ERROR));
	philos = spawn(&args, forks);
	if (!(philos))
		return (error_output(NULL, NULL, MALLOC_ERROR));
	while (args.status == 0)
	{
		if (args.eat_nb == args.nb)
			break ;
		usleep(100);
	}
	return (full_free(philos, forks, &args));
}
