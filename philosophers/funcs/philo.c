/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:18:16 by hardella          #+#    #+#             */
/*   Updated: 2022/01/18 08:34:20 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	philo_moves(void *philo)
{
	t_ph	*p;

	p = (t_ph *)philo;
	while (1)
	{
		if (get_time >= p->die + 5)
			died();
	}
	return ;
}

void	health(void *philo)
{
	return ;
}

void	*philo_control(void *philo)
{
	pthread_t	id;
	t_ph		*p;
	int			i;

	p = (t_ph *)philo;
	i = 0;
	pthread_create(&id, NULL, &health, p);
	pthread_detach(id);
	while (i < p->arg->met)
	{
		philo_moves(p);
		i++;
	}
	return (NULL);
}

t_ph	*spawn(t_p *arg)
{
	t_ph	*phs;
	int		i;

	phs = malloc(sizeof(t_p) * arg->nb);
	if (!phs)
		return (NULL);
	i = 0;
	while (i < arg->nb)
		pthread_mutex_init(&phs[i++].f, NULL);
	i = 0;
	while (i < arg->nb)
	{
		if (pthread_create(&phs[i].tid, NULL, &philo_control, &phs[i++]))
			error_pthread_create(phs);
		usleep(5);
	}
	i = 0;
	while (i < arg->nb)
		pthread_detach(&phs[i].tid);
}

int	main(int argc, char **argv)
{
	t_p		arg;
	t_ph	*philos;

	if (argc == 5 || argc == 6)
		pars_init(argc, argv, &arg);
	else
		error_input();
	philos = spawn(&arg);
}
