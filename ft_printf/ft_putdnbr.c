/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:57:14 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 20:12:14 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdnbr(unsigned int n, int *r_b)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0', r_b);
	else
	{
		ft_putnbr(n / 10, r_b);
		ft_putchar(n % 10 + '0', r_b);
	}
}
