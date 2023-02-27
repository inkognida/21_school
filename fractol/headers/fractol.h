/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:46:35 by hardella          #+#    #+#             */
/*   Updated: 2023/02/27 15:33:47 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		500
# define HEIGHT		500
# define SCALE		2;

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../MinilibX/X11/mlx.h"

typedef struct s_complex{
	double	r;
	double	i;
}				t_complex;

typedef struct s_axis{
	double	x;
	double	y;
}				t_axis;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}					t_image;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_axis			axis;
	t_complex		c;
	t_complex		z;
	t_axis			z_axis;
	double			zoom_x;
	double			zoom_y;
	double			zoom;
	t_axis			z_zoom;
	double			z_zoom_const;
	double			zoom_scale;
	double			max_iter;
	double			temp;
	int				i;
	int				name;
	int				bonus_key;
}				t_f;

int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strlen(char *str);
void		init_f(t_f *f, char *name);
void		help(void);
void		get_f(char *f_name);
void		mandelbrot(void);
void		julia(int key);
long int	color(int it);
long int	color2(int it);
long int	color3(int it);
void		my_mlx_pixel_put(t_f *f, int x, int y, int color);
void		draw_mandelbrot(t_f *f);
int			key_hook(int key, t_f *f);
void		zoom_set(int key, int x, int y, t_f *f);
int			zoom_change(int key, int x, int y, t_f *f);
int			close_window(int key, t_f *f);
void		get_mandelbrot_values(t_f *f);
void		mandelbrot(void);
void		draw_julia(t_f *f);
void		get_julia_values(t_f *f);
void		draw(t_f *f);
int			escape_hook(int key, t_f *f);
void		get_bonus_values(t_f *f);
void		draw_bonus(t_f *f);
void		bonus(int key);
void		draw_bonus_color(t_f *f);
int			color_hook(int key, t_f *f);

#endif