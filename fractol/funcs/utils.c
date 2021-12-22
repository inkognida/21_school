/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:43:13 by hardella          #+#    #+#             */
/*   Updated: 2021/12/21 19:57:56 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	char			*r1;
	char			*r2;
	int				check;

	r1 = (char *) s1;
	r2 = (char *) s2;
	i = 0;
	while ((r1[i] || r2[i]) && i < n)
	{
		if (r1[i] != r2[i])
		{
			check = r1[i] - r2[i];
			return (check);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
