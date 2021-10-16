/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:40:17 by hardella          #+#    #+#             */
/*   Updated: 2021/10/16 21:26:44 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*ft_strjoin(char *s1, char *s2);
void		*ft_memcpy(void *dst, void *src, int n);
int			ft_strlcpy(char *dst, char *src, int dstsize);
char		*ft_strchr(char *s, int c);
int			ft_strlen(char *str);

char		*get_next_line(int fd);

#endif 