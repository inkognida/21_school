/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:57:17 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 18:16:14 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putvoid(unsigned long long int v, int *r_b)
{
	char	*base;

	base = "0123456789abcdef";
	if (v >= 16)
		ft_putvoid(v / 16, r_b);
	ft_putchar(base[v % 16], r_b);
}
