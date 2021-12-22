/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:46:35 by hardella          #+#    #+#             */
/*   Updated: 2021/12/22 19:26:27 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH		1000
# define HEIGHT		1000
# define MAX_IT		255

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_complex{
	double	r;
	double	i;
}				t_complex;

typedef struct s_axis{
	double	x;
	double	y;
}				t_axis;
//bpp (bit_per_pixel), ll (line_lenght)
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}					t_image;

/*
c - const, i - iteration, z - param of formula
temp - param for formula, 
zoom - scaling 
z_axis - axis of scale

*/
typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	t_image			img;
	t_complex		axis;
	t_complex		c;
	t_complex		z;
	t_axis			z_axis;
	t_axis			zoom;
	double			temp;
	int				i;
}				t_f;

int	ft_strncmp(char *s1, char *s2, int n);
int	ft_strlen(char *str);

#endif