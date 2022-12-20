/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:14:54 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 11:33:03 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
//z^2 + c

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	long double	nbx;
	long double	nby;
	long double	x;
	long double	y;
	int			i;
	long double	tmp;

	x = 1080;
	y = 1080;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "Fract-ol");
	img.img = mlx_new_image(mlx, x--, y--);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x)
	{
		while (y)
		{
			i = 0;
			nbx = 0;
			nby = 0;
			while (i < 150 && ((nbx * nbx) + (nby * nby) <= 4.0))
			{
				tmp = nbx * nbx - nby * nby + (((x	/ 1080.0) * 2.47) - 1.5);
				nby = 2.0 * nbx * nby + (((y / 1080.0) * 2.24) - 1.12);
				nbx = tmp;
				i++;
			}

			int rgb = i / 50.0 * 255;
			int test = rgb * 0.5;
			if (i == 150)	
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				my_mlx_pixel_put(&img, x, y, (0 << 24 | test << 16 | test << 8 | rgb));
			y--;
		}
		y = 1079;
		x--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
