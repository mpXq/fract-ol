/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot-set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 19:20:07 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"
//mset = mandelbrot set
//cx = constant x
//cy = constant y

long double	cx(long double x, long double zoom)
{
	long double	rep;

	rep = (((x) / (1080.0 * zoom)) * 2.47) - 1.5;
	return (rep);
}

long double	cy(long double y, long double zoom)
{
	long double	rep;

	rep = (((y) / (1080.0 * zoom)) * 2.24) - 1.12;
	return (rep);
}

int	pixelcalculator(long double x, long double y, long double zoom)
{
	int			i;
	t_fractol	mset;

	i = -1;
	mset.nbx = 0;
	mset.nby = 0;
	while (++i < MAXITERATION
		&& ((mset.nbx * mset.nbx) + (mset.nby * mset.nby) <= 4.0))
	{
		mset.tmp = mset.nbx * mset.nbx - mset.nby * mset.nby + cx(x, zoom);
		mset.nby = 2.0 * mset.nbx * mset.nby + cy(y, zoom);
		mset.nbx = mset.tmp;
	}
	return (i);
}

void	mspawner(t_data img, t_fractol *mset)
{
	mset->x = 0;
	while (mset->x ++ < 1079)
	{
		mset->y = 0;
		while (mset->y ++ < 1079)
		{
			mset->rgb = pixelcalculator(mset->x, mset->y,
					mset->zoom) / 50.0 * 255.0;
			my_mlx_pixel_put(&img, mset->x, mset->y,
				pixelcalculator(mset->x, mset->y, mset->zoom) * 3);
			if (pixelcalculator(mset->x, mset->y, mset->zoom) == MAXITERATION)
				my_mlx_pixel_put(&img, mset->x, mset->y, 0x00000000);
		}
	}
}

void	mandelbrot_set(void)
{
	t_program	program;

	program.fractol.zoom = 1;
	program.mlx = mlx_init();
	program.window = new_window(program.mlx, 1080, 1080, "Mandelbrot set");
	program.img.img = mlx_new_image(program.mlx, 1080, 1080);
	program.img.addr = mlx_get_data_addr(program.img.img,
			&program.img.bits_per_pixel, &program.img.line_length,
			&program.img.endian);
	mspawner(program.img, &program.fractol);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.img.img, 0, 0);
	mlx_mouse_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
