/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:48:39 by hardella          #+#    #+#             */
/*   Updated: 2021/12/24 20:14:35 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_f *f, int x, int y, int color)
{
	char	*dt;

	dt = f->img.addr + (y * f->img.ll + x * (f->img.bpp / 8));
	*(unsigned int *)dt = color;
}

int	close_window(int key, t_f *f)
{
	if (key == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_image(f->mlx, f->img.img);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		get_f(argv[1]);
	else
		help();
}
