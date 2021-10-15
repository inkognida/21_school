/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:57:34 by hardella          #+#    #+#             */
/*   Updated: 2021/10/15 09:49:53 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(char *s, int c)
{
	char	temp;

	temp = c;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
		if (*s == '\0')
			return (NULL);
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		g;

	i = 0;
	g = 0;
	while (src[i])
		i++;
	copy = (char *) malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	while (src[g])
	{
		copy[g] = src[g];
		g++;
	}
	copy[g] = '\0';
	return (copy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*new_str(int b)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (b + 1));
	if (!(str))
		return (NULL);
	while (b)
	{
		*str = '\0';
		str++;
		b--;
	}
	return (str);
}
