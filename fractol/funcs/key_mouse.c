/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:13:11 by hardella          #+#    #+#             */
/*   Updated: 2021/12/27 14:10:03 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	key_hook(int key, t_f *f)
{
	if (key == 1)
		f->z_axis.y -= 0.1 / f->zoom;
	if (key == 13)
		f->z_axis.y += 0.1 / f->zoom;
	if (key == 2)
		f->z_axis.x -= 0.1 / f->zoom;
	if (key == 0)
		f->z_axis.x += 0.1 / f->zoom;
	if (f->name == 0)
		draw_mandelbrot(f);
	if (f->name == 1)
		draw_julia(f);
	if (f->name == 3)
		draw_bonus(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
}

void	zoom_set(int key, int x, int y, t_f *f)
{
	(void)key;
	f->z_zoom.y = f->z_zoom.x;
	f->z_zoom.x = (f->z_zoom_const / f->zoom);
	f->z_axis.x += (f->z_zoom.y - f->z_zoom.x) / SCALE;
	f->z_axis.y += (f->z_zoom.y - f->z_zoom.x) / SCALE;
	f->zoom_scale = f->z_zoom.x / WIDTH;
	f->zoom_x = WIDTH / f->z_zoom.x;
	f->zoom_y = HEIGHT / f->z_zoom.x;
	x = x - WIDTH / SCALE;
	y = y - HEIGHT / SCALE;
	f->z_axis.x += (x * (f->z_zoom.y / WIDTH)) - (x * f->zoom_scale);
	f->z_axis.y += (y * (f->z_zoom.y / HEIGHT)) - (y * f->zoom_scale);
	if (f->name == 0)
		draw_mandelbrot(f);
	if (f->name == 1)
		draw_julia(f);
	if (f->name == 3)
		draw_bonus(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

int	zoom_change(int key, int x, int y, t_f *f)
{
	if (key == 1 || key == 4)
	{
		f->zoom *= 1.1;
		if (f->max_iter < 250)
			f->max_iter += 1;
	}
	if (key == 2 || key == 5)
	{
		f->zoom /= 1.1;
		if (f->max_iter > 50)
			f->max_iter -= 1;
	}
	zoom_set(key, x, y, f);
	return (0);
}

int	escape_hook(int key, t_f *f)
{
	if (key == 53)
	{
		mlx_destroy_image(f->mlx, f->img.img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}
