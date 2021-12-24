/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:12:47 by hardella          #+#    #+#             */
/*   Updated: 2021/12/24 20:13:53 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	draw(t_f *f)
{
	if (f->i < f->max_iter)
		my_mlx_pixel_put(f, f->axis.x, f->axis.y, color(f->i));
	else
		my_mlx_pixel_put(f, f->axis.x, f->axis.y, 0x0);
}

void	draw_mandelbrot(t_f *f)
{
	f->axis.x = 0;
	while (f->axis.x < HEIGHT)
	{
		f->axis.y = 0;
		while (f->axis.y < WIDTH)
		{
			f->c.r = f->axis.x / f->zoom_x + f->z_axis.x;
			f->c.i = f->axis.y / f->zoom_y + f->z_axis.y;
			f->z.r = 0;
			f->z.i = 0;
			f->i = 0;
			while ((f->z.r * f->z.r) +(f->z.i * f->z.i) <= 4 \
						&& f->i < f->max_iter)
			{
				f->temp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
				f->z.i = 2.0 * f->z.r * f->z.i + f->c.i;
				f->z.r = f->temp;
				f->i++;
			}
			draw(f);
			f->axis.y++;
		}
		f->axis.x++;
	}
}

void	get_mandelbrot_values(t_f *f)
{
	f->zoom = 1;
	f->z_axis.x = -2;
	f->z_axis.y = -1.35;
	f->z_zoom.x = 2.8;
	f->z_zoom_const = 2.8;
	f->zoom_x = WIDTH / 2.8;
	f->zoom_y = HEIGHT / 2.8;
	f->max_iter = 50;
	f->name = 0;
}

void	mandelbrot(void)
{
	t_f	f;

	init_f(&f, "Mandelbrot");
	get_mandelbrot_values(&f);
	draw_mandelbrot(&f);
	mlx_hook(f.win, 2, 1L << 2, escape_hook, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, zoom_change, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
}
