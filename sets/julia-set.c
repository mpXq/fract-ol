/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia-set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/21 14:01:09 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"
//mset = mandelbrot set

static int	pcalculator(long double x, long double y, double zx, double zy)
{
	int			i;
	t_fractol	*mset;

	i = -1;
	mset = malloc(sizeof(t_fractol));
	mset->nbx = ((x / 1080.0) * 4) - 2;
	mset->nby = ((y / 1080.0) * 4) - 2;
	while (++i < MAXITERATION
		&& ((mset->nbx * mset->nbx) + (mset->nby * mset->nby) <= 4.0))
	{
		mset->tmp = mset->nbx * mset->nbx - mset->nby * mset->nby + zx;
		mset->nby = 2.0 * mset->nbx * mset->nby - zy;
		mset->nbx = mset->tmp;
	}
	free(mset);
	return (i);
}

static void	jspawner(t_data img, t_fractol *mset, double zx, double zy)
{
	mset->x = 1080;
	while (mset->x --)
	{
		mset->y = 1080;
		while (mset->y --)
		{
			if (!mset->rgb)
				mset->rgb = pcalculator(mset->x, mset->y, zx, zy)
					/ 50.0 * 255.0;
			my_mlx_pixel_put(&img, mset->x, mset->y, rgb(mset->rgb));
			if (pcalculator(mset->x, mset->y, zx, zy) == MAXITERATION)
				my_mlx_pixel_put(&img, mset->x, mset->y, 0);
		}
	}
}

void	julia_set(long double zx, long double zy)
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
	jspawner(img, mset, zx, zy);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free(mset);
}
