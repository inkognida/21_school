/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:37:16 by hardella          #+#    #+#             */
/*   Updated: 2021/12/28 16:59:33 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_phio
{
	int	eat_time;
	int	die_time;
	int	sleep_time;
	int	total_philos;
	int	must_eat_times;

}				t_philo;

int			ft_strlen(char *str);
long int	is_num(char *num);
int			check_arg(char *num);
void		pars_init(int argc, char **argv);
void		error_input(void);
void		accept(int f, int i);

#endif