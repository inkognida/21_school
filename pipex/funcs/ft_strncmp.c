/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:26:58 by hardella          #+#    #+#             */
/*   Updated: 2021/12/07 18:27:56 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	unsigned char	*r1;
	unsigned char	*r2;
	unsigned int	check;

	r1 = (unsigned char *) s1;
	r2 = (unsigned char *) s2;
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
