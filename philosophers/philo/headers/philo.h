/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:37:16 by hardella          #+#    #+#             */
/*   Updated: 2022/01/21 21:23:15 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define MIN -2147483648
# define MAX 2147483647
# define THINK "is thinking"
# define FORK "has taken fork"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"
# define DED 2
# define MET 1
# define PARS_ERROR 1
# define MUTEX_ERROR 2
# define MALLOC_ERROR 3
# define PTHREAD_ERROR 4
# define MUTEX_INIT_ERROR 5

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_p
{
	int					nb;
	int					et;
	int					dt;
	int					st;
	int					met;
	int					eat_nb;
	unsigned long int	start_time;
	int					status;
	pthread_mutex_t		print;
}				t_p;

typedef struct s_ph
{
	int					id;
	int					indx;
	pthread_t			tid;
	t_fork				*min;
	t_fork				*max;
	unsigned long int	die_time;
	int					eat_max;
	t_p					*arg;
}				t_ph;

void				game(t_ph *philo);
void				*health(void *p);
void				*control(void *p);
void				get_forks(t_ph *phs, t_p *arg, t_fork *forks);
t_ph				*spawn(t_p *arg, t_fork *forks);
int					full_free(t_ph *philos, t_fork *forks, t_p *args);
int					ft_strlen(char *str);
int					pars_init(int argc, char **argv, t_p *arg);
void				accept(int value, t_p *arg, int index);
int					exc(long int value, int f);
int					ft_atoi(char *str, int f);
int					error_output(t_ph *phs, t_fork *forks, int flag);
unsigned long int	get_time(void);
void				print(char *s, t_p *arg, int id);
void				philo_exit(t_ph *philos, t_p *args, int f, t_fork *forks);

#endif