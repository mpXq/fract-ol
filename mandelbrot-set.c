/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot-set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 11:43:11 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"
//mset = mandelbrot set
//cx = constant x
//cy = constant y

static long double	cx(long double x)
{
	long double	rep;

	rep = ((x / 1080.0) * 2.47) - 1.5;
	return (rep);
}

static long double	cy(long double y)
{
	long double	rep;

	rep = ((y / 1080.0) * 2.47) - 1.5;
	return (rep);
}

static int	pixelcalculator(long double x, long double y)
{
	int			i;
	t_fractol	*mset;

	i = 0;
	mset = malloc(sizeof(t_fractol));
	mset->nbx = 0;
	mset->nby = 0;
	while (i < MAXITERATION
		&& ((mset->nbx * mset->nbx) + (mset->nby * mset->nby) <= 4.0))
	{
		mset->tmp = pow(mset->nbx, 2) + pow(mset->nby, 2) + cx(x);
		mset->nby = 2.0 * mset->nbx * mset->nby + cy(y);
		mset->nbx = mset-> tmp;
	}
	free(mset);
	return (i);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_fractol	*mset;

	mset = malloc(sizeof(t_fractol));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "Mandelbrot set");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mset->x = 1080;
	while (mset->x --)
	{
		mset->y = 1080;
		while (mset->y --)
		{
			mset->rgb = pixelcalculator(mset->x, mset->y) / 50.0 * 255;
			if (pixelcalculator(mset->x, mset->y) == MAXITERATION)
				my_mlx_pixel_put(&img, mset->x, mset->y, 0x00000000);
			else
				my_mlx_pixel_put(&img, mset->x, mset->y, rgb(mset->rgb));
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
