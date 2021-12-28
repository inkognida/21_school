/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:18:16 by hardella          #+#    #+#             */
/*   Updated: 2021/12/28 13:47:43 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	error_input(void)
{
	write(2, "Error input\n", ft_strlen("Error input\n"));
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
		pars_init(argc, argv);
	else
		error_input();
}
