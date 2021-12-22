/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:48:39 by hardella          #+#    #+#             */
/*   Updated: 2021/12/22 19:29:23 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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

void	my_mlx_pixel_put(t_f *f, int x, int y, int color)
{
	char	*dt;

	dt = f->img.addr + (y * f->img.ll + x * (f->img.bpp / 8));
	*(unsigned int *)dt = color;
}

//be careful with f->i++
void	draw_simple_mandelbrot(t_f *f)
{
	f->axis.r = 0;
	while (f->axis.r < HEIGHT)
	{
		f->axis.i = 0;
		while (f->axis.i < WIDTH)
		{
			f->c.r = (f->axis.i - WIDTH / 2.0) * 4.0 / WIDTH;
			f->c.i = (f->axis.r - HEIGHT / 2.0) * 4.0 / WIDTH;
			f->z.r = 0;
			f->z.i = 0;
			f->i = 0;
			while ((f->z.r * f->z.r) +(f->z.i * f->z.i) <= 4 && f->i++ < MAX_IT)
			{
				f->temp = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
				f->z.i = 2.0 * f->z.r * f->z.i + f->c.i;
				f->z.r = f->temp;
			}
			if (f->i < MAX_IT)
				my_mlx_pixel_put(f, f->axis.i, f->axis.r, color(f->i));
			else
				my_mlx_pixel_put(f, f->axis.i, f->axis.r, 0x0);
			f->axis.i++;
		}
		f->axis.r++;
	}
}

/*
1 - left but (mouse)
2 - right but (mouse)
3 - middle (mouse)
4 - scrolling back
5 - scrolling forward
*/

int	move(int key, t_f *f)
{
	(void)key;
	(void)f;
	return (0);
}

int	mouse_hook(int key, int x, int y, t_f *f)
{
	printf("%d\n", key);
	my_mlx_pixel_put(f, x, y, 0x995700);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (0);
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

void	init_f(t_f *f, char *name)
{ 
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, name);
	if (!f->win)
		exit(1);
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
		exit(-1);
	f->img.addr = mlx_get_data_addr(f->img.img, \
			&(f->img.bpp), &(f->img.ll), &(f->img.endian));
}

void	mandelbrot(void)
{
	t_f	f;

	init_f(&f, "Mandelbrot");
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_key_hook(f.win, close_window, &f);
	draw_simple_mandelbrot(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img.img, 0, 0);
	mlx_loop(f.mlx);
}

void	julia(void)
{
	return ;
}

void	help(void)
{
	printf("usage: ./f [name]\n");
	printf("avaliable names:\n\t 1) Mandelbrot\n\t 2) Julia\n");
}

void	get_f(char *f_name)
{
	if (ft_strncmp(f_name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		mandelbrot();
	else if (ft_strncmp(f_name, "Julia", ft_strlen("Julia")) == 0)
		julia();
	else
		help();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		get_f(argv[1]);
	else
		help();
}
