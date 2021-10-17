/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:57:14 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 17:28:58 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *r_b)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", r_b);
	else if (n < 0)
	{
		ft_putchar('-', r_b);
		ft_putnbr(n * -1, r_b);
	}
	else if (n >= 0 && n < 10)
		ft_putchar(n + '0', r_b);
	else
	{
		ft_putnbr(n / 10, r_b);
		ft_putchar(n % 10 + '0', r_b);
	}
}
