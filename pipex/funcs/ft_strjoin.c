/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:30:40 by hardella          #+#    #+#             */
/*   Updated: 2021/12/06 22:34:14 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*r;

	i = 0;
	j = 0;
	k = -1;
	if (!(s1) || !(s2))
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	r = (char *)malloc(sizeof(char) * (i + j + 1));
	if (r == NULL)
		return (NULL);
	while (s1[++k])
		r[k] = s1[k];
	i = -1;
	while (s2[++i])
		r[k + i] = s2[i];
	r[k + i] = '\0';
	return (r);
}
