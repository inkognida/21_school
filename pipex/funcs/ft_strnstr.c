/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:11:30 by hardella          #+#    #+#             */
/*   Updated: 2021/12/07 20:43:58 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	if (len == 0 && (ft_strlen(needle) != 0))
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)) && \
			len >= ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
