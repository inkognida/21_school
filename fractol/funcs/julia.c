/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:32:55 by hardella          #+#    #+#             */
/*   Updated: 2021/12/27 18:32:11 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	get_julia_values(t_f *f)
{
	f->c.r = 0;
	f->c.i = -0.8;
	f->z_axis.x = -1.2;
	f->z_axis.y = -1.1;
	f->z_zoom.x = 2.2;
	f->z_zoom_const = 2.2;
	f->zoom = 1;
	f->zoom_x = WIDTH / 2.2;
	f->zoom_y = HEIGHT / 2.2;
	f->max_iter = 25;
	f->name = 1;
}

void	get_julia_values1(t_f *f)
{
	f->c.r = -0.8;
	f->c.i = 0.156;
	f->z_axis.x = -1.2;
	f->z_axis.y = -1.1;
	f->z_zoom.x = 2.2;
	f->z_zoom_const = 2.2;
	f->zoom = 1;
	f->zoom_x = WIDTH / 2.2;
	f->zoom_y = HEIGHT / 2.2;
	f->max_iter = 25;
	f->name = 1;
}

void	get_julia_values2(t_f *f)
{
	f->c.r = -0.999;
	f->c.i = 0.999;
	f->z_axis.x = -1.2;
	f->z_axis.y = -1.1;
	f->z_zoom.x = 2.2;
	f->z_zoom_const = 2.2;
	f->zoom = 1;
	f->zoom_x = WIDTH / 2.2;
	f->zoom_y = HEIGHT / 2.2;
	f->max_iter = 25;
	f->name = 1;
}

void	draw_julia(t_f *f)
{
	f->axis.x = 0;
	while (f->axis.x < WIDTH)
	{
		f->axis.y = 0;
		while (f->axis.y < HEIGHT)
		{
			f->z.r = f->axis.x / f->zoom_x + f->z_axis.x;
			f->z.i = f->axis.y / f->zoom_y + f->z_axis.y;
			f->i = 0;
			while ((f->z.r * f->z.r) +(f->z.i * f->z.i) <= 4 \
					&& f->i < f->max_iter)
			{
				f->temp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
				f->z.i = 2.0 * f->z.r * f->z.i + f->c.i;
				f->z.r = f->temp;
				f->i++;
			}
			if (f->i < f->max_iter)
				my_mlx_pixel_put(f, f->axis.x, f->axis.y, color2(f->i));
			else
				my_mlx_pixel_put(f, f->axis.x, f->axis.y, 0x0);
			f->axis.y++;
		}
		f->axis.x++;
	}
}

void	julia(int key)
{
	t_f	f;

	init_f(&f, "Julia");
	if (key == 0)
		get_julia_values(&f);
	else if (key == 1)
		get_julia_values1(&f);
	else if (key == 2)
		get_julia_values2(&f);
	draw_julia(&f);
	mlx_hook(f.win, 2, 1L << 2, escape_hook, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, zoom_change, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
}
