/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:58:18 by hardella          #+#    #+#             */
/*   Updated: 2021/12/27 14:35:18 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	draw_bonus_color(t_f *f)
{
	if (f->bonus_key == 0)
	{
		if (f->i < f->max_iter)
			my_mlx_pixel_put(f, f->axis.x, f->axis.y, color(f->i));
		else
			my_mlx_pixel_put(f, f->axis.x, f->axis.y, 0x0);
	}
	else if (f->bonus_key == 1)
	{
		if (f->i < f->max_iter)
			my_mlx_pixel_put(f, f->axis.x, f->axis.y, color3(f->i));
		else
			my_mlx_pixel_put(f, f->axis.x, f->axis.y, 0x0);
	}
}

void	get_bonus_values(t_f *f)
{
	f->c.r = -2;
	f->c.i = 0.5;
	f->zoom = 1;
	f->z_axis.x = -2;
	f->z_axis.y = -1;
	f->z_zoom_const = 2.8;
	f->z_zoom.x = 2.8;
	f->zoom_x = WIDTH / 2.8;
	f->zoom_y = HEIGHT / 2.8;
	f->max_iter = 50;
	f->name = 3;
	f->bonus_key = 0;
}

void	draw_bonus(t_f *f)
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
				f->z.i = -(2.0 * f->z.r * f->z.i) + f->c.i;
				f->z.r = f->temp;
				f->i++;
			}
			draw_bonus_color(f);
			f->axis.y++;
		}
		f->axis.x++;
	}
}

int	color_hook(int key, t_f *f)
{
	if (key == 257)
	{
		if (f->bonus_key == 0)
			f->bonus_key = 1;
		else if (f->bonus_key == 1)
			f->bonus_key = 0;
		draw_bonus(f);
	}
	else if (key == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_image(f->mlx, f->img.img);
		exit(0);
	}
	return (0);
}

void	bonus(int key)
{
	t_f	f;

	init_f(&f, "Tricorn");
	if (key == 3)
		get_bonus_values(&f);
	draw_bonus(&f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 2, 1L << 2, color_hook, &f);
	mlx_mouse_hook(f.win, zoom_change, &f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
}
