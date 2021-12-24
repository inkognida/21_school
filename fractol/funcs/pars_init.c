/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:43:10 by hardella          #+#    #+#             */
/*   Updated: 2021/12/24 19:55:35 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

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

void	help(void)
{
	printf("usage: ./f [name]\n");
	printf("avaliable names:\n\t 1) Mandelbrot\n\t");
	printf(" 2) Julia\n\t 3) Julia1\n\t 4) Julia2 \n");
}

void	get_f(char *f_name)
{
	if (ft_strncmp(f_name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		mandelbrot();
	else if (ft_strncmp(f_name, "Julia", ft_strlen(f_name)) == 0)
		julia(0);
	else if (ft_strncmp(f_name, "Julia1", ft_strlen(f_name)) == 0)
		julia(1);
	else if (ft_strncmp(f_name, "Julia2", ft_strlen(f_name)) == 0)
		julia(2);
	else
		help();
}
