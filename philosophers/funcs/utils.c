/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:20:13 by hardella          #+#    #+#             */
/*   Updated: 2022/01/18 06:04:08 by hardella         ###   ########.fr       */
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

void	error_input(void)
{
	write(2, "Error input\n", ft_strlen("Error input\n"));
	exit(1);
}

void	error_pthread_create(t_ph *phs)
{
	free(phs);
	write(2, "Error pthread creating\n", ft_strlen("Error pthread creating\n"));
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
