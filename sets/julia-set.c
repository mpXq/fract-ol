/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia-set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:42:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 15:11:52 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"

int	jpixelcalculator(long double x, long double y, double cx, double cy)
{
	int			i;
	t_fractol	mset;

	i = -1;
	mset.nbx = ((x / 540.) * 4) - 2;
	mset.nby = ((y / 540.) * 4) - 2;
	while (++i < MAXITERATION
		&& ((mset.nbx * mset.nbx) + (mset.nby * mset.nby) <= 4.0))
	{
		mset.tmp = mset.nbx * mset.nbx - mset.nby * mset.nby + cx;
		mset.nby = 2.0 * mset.nbx * mset.nby - cy;
		mset.nbx = mset.tmp;
	}
	return (i);
}

void	jspawner(t_data img, t_fractol *mset, double cx, double cy)
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
				jpixelcalculator(x, y, cx, cy) * 3);
			if (jpixelcalculator(x, y, cx, cy)
				== MAXITERATION)
				my_mlx_pixel_put(&img, x, y, mset->rgb);
			y++;
		}
		x++;
	}
}

void	julia_set(long double cx, long double cy)
{
	t_program	program;

	program.fractol.rgb = 0;
	program.fractol.zoom = 1;
	program.fractol.mx = 0;
	program.fractol.my = 0;
	program.fractol.tmx = 0;
	program.fractol.tmy = 0;
	program.mlx = mlx_init();
	program.window = new_window(program.mlx, 540, 540, "Julia set");
	program.img.img = mlx_new_image(program.mlx, 540, 540);
	program.img.addr = mlx_get_data_addr(program.img.img,
			&program.img.bits_per_pixel, &program.img.line_length,
			&program.img.endian);
	jspawner(program.img, &program.fractol, cx, cy);
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.img.img, 0, 0);
	mlx_mouse_hook(program.window.reference, ft_input, &program);
	mlx_hook(program.window.reference, 17, 1L << 2, ft_close, &program);
	mlx_key_hook(program.window.reference, ft_inputk, &program);
	mlx_loop(program.mlx);
}
