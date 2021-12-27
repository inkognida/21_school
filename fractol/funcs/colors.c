/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:14:39 by hardella          #+#    #+#             */
/*   Updated: 2021/12/27 14:06:03 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

long int	color(int it)
{
	int	colors[16];

	colors[0] = 0x421E0F;
	colors[1] = 0x19071A;
	colors[2] = 0x09012F;
	colors[3] = 0x040449;
	colors[4] = 0x000764;
	colors[5] = 0x0C2C8A;
	colors[6] = 0x1852B1;
	colors[7] = 0x397DD1;
	colors[8] = 0x86B5E5;
	colors[9] = 0xD3ECF8;
	colors[10] = 0xF1E9BF;
	colors[11] = 0xF8C95F;
	colors[12] = 0xFFAA00;
	colors[13] = 0xCC8000;
	colors[14] = 0x995700;
	colors[15] = 0x6A3403;
	return (colors[it % 16]);
}

long int	color2(int it)
{
	int	colors[16];

	colors[0] = 0x421E0F;
	colors[1] = 0x19071A;
	colors[2] = 0x09012F;
	colors[3] = 0x040449;
	colors[4] = 0x000764;
	colors[5] = 0x0C2C8A;
	colors[6] = 0x1852B1;
	colors[7] = 0x397DD1;
	colors[8] = 0x86B5E5;
	colors[9] = 0xD3ECF8;
	colors[10] = 0xF1E9BF;
	colors[11] = 0xF8C95F;
	colors[12] = 0xFFAA00;
	colors[13] = 0xCC8000;
	colors[14] = 0x995700;
	colors[15] = 0x6A3403;
	if (it % 16 == 0)
		return (0x0);
	return (colors[it % 16]);
}

long int	color3(int it)
{
	int	colors[5];

	colors[0] = 0x443d93;
	colors[1] = 0x5c54ae;
	colors[2] = 0x465c9c;
	colors[3] = 0x5c61c5;
	colors[4] = 0x83a1f3;
	return (colors[it % 5]);
}
