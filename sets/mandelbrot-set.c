/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot-set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 11:07:01 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"
//mset = mandelbrot set
//cx = constant x
//cy = constant y

long double	cx(long double x, long double mx, long double zoom)
{
	long double	rep;

	rep = (((x + mx) / (540. * zoom)) * 2.47) - 1.5;
	return (rep);
}

long double	cy(long double y, long double my, long double zoom)
{
	long double	rep;

	rep = (((y + my) / (540. * zoom)) * 2.24) - 1.12;
	return (rep);
}

int	pixelcalculator(long double x, long double y, long double zoom,
		t_fractol *m)
{
	int			i;
	t_fractol	mset;

	i = -1;
	mset.nbx = 0.;
	mset.nby = 0.;
	while (++i < MAXITERATION
		&& ((mset.nbx * mset.nbx) + (mset.nby * mset.nby) <= 4.0))
	{
		mset.tmp = mset.nbx * mset.nbx - mset.nby * mset.nby
			+ cx(x, m->mx, zoom);
		mset.nby = 2.0 * mset.nbx * mset.nby + cy(y, m->my, zoom);
		mset.nbx = mset.tmp;
	}
	return (i);
}

void	mspawner(t_data img, t_fractol *mset)
{
	int	x;
	int	y;

	x = 0;
	while (x < 539)
	{
		y = 0;
		while (y < 539)
		{
			my_mlx_pixel_put(&img, x, y,
				pixelcalculator(x, y, mset->zoom, mset) * 3);
			if (pixelcalculator(x, y, mset->zoom, mset)
				== MAXITERATION)
				my_mlx_pixel_put(&img, x, y, mset->rgb);
			y++;
		}
		x++;
	}
}

void	mandelbrot_set(void)
{
	t_program	program;

	program.fractol.zoom = 1;
	program.fractol.mx = 0;
	program.fractol.my = 0;
	program.fractol.tmx = 0;
	program.fractol.tmy = 0;
	program.mlx = mlx_init();
	program.window = new_window(program.mlx, 540, 540, "Mandelbrot set");
	program.img.img = mlx_new_image(program.mlx, 540, 540);
	program.img.addr = mlx_get_data_addr(program.img.img,
			&program.img.bits_per_pixel, &program.img.line_length,
			&program.img.endian);
	mspawner(program.img, &program.fractol);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.img.img, 0, 0);
	mlx_mouse_hook(program.window.reference, ft_input, &program);
	mlx_loop(program.mlx);
}
