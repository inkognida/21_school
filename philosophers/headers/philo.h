/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:37:16 by hardella          #+#    #+#             */
/*   Updated: 2022/01/18 08:34:28 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <time.h>

# include <stdio.h>

# define MIN -2147483648
# define MAX 2147483647

typedef struct s_p
{
	int	nb;
	int	et;
	int	dt;
	int	st;
	int	met;
}				t_p;

typedef struct s_ph
{
	int				id;
	pthread_t		tid;
	pthread_mutex_t	f;
	pthread_mutex_t	*nf;
	int				die;
	t_p				*arg;
}				t_ph;

int			ft_strlen(char *str);
void		pars_init(int argc, char **argv, t_p *arg);
void		error_input(void);
void		accept(int value, t_p *arg, int index);
int			exc(long int value, int f);
int			ft_atoi(char *str, int f);
int			get_time(void);

#endif