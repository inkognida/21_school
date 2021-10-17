/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:58:19 by hardella          #+#    #+#             */
/*   Updated: 2021/10/17 17:28:57 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexup(unsigned int h, int *r_b)
{
	char			*base;

	base = "0123456789ABCDEF";
	if (h >= 16)
		ft_puthexup(h / 16, r_b);
	if (h >= 97 && h <= 122)
		h = h - 32;
	ft_putchar(base[h % 16], r_b);
}
