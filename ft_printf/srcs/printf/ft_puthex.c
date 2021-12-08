/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:58:19 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 17:28:55 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int h, int *r_b)
{
	char			*base;

	base = "0123456789abcdef";
	if (h >= 16)
		ft_puthex(h / 16, r_b);
	ft_putchar(base[h % 16], r_b);
}
