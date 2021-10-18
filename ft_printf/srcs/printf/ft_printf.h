/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:07:52 by hardella          #+#    #+#             */
/*   Updated: 2021/10/18 14:10:58 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *r_b);
void	ft_putendl(char *s);
void	ft_putstr(char *s, int *r_b);
void	ft_putvoid(unsigned long long int v, int *r_b);
void	ft_putnbr(int n, int *r_b);
void	ft_putdnbr(unsigned int n, int *r_b);
void	ft_puthex(unsigned int h, int *r_b);
void	ft_puthexup(unsigned int h, int *r_b);

#endif 