/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:23:01 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/21 21:14:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"

int	ft_input(int key, int x, int y, t_program *param)
{
	if (key == 5 || key == 1 || key == 4)
	{
		if (key == 4 && param->fractol.zoom > 2)
		{
			param->fractol.mx = x;
			param->fractol.my = y;
			param->fractol.zoom--;
		}
		else if (key == 4 && param->fractol.zoom == 2)
		{
			param->fractol.mx = 0;
			param->fractol.my = 0;
			param->fractol.zoom--;
		}
		else if (key == 5 || key == 1)
		{
			param->fractol.mx = x;
			param->fractol.my = y;
			param->fractol.zoom *= 2;
		}
		mlx_clear_window(param->mlx, param->window.reference);
		param->img.addr = mlx_get_data_addr(param->img.img,
			&param->img.bits_per_pixel, &param->img.line_length,
			&param->img.endian);
		mspawner(param->img, &param->fractol);
		mlx_put_image_to_window(param->mlx, param->window.reference,
			param->img.img, 0, 0);
	}
	else if (key == 2)
	{
		if (param->fractol.rgb == 0x00FFFFFF)
			param->fractol.rgb = 0;
		else
			param->fractol.rgb = 0x00FFFFFF;
		mspawner(param->img, &param->fractol);
		mlx_put_image_to_window(param->mlx, param->window.reference,
			param->img.img, 0, 0);
	}
	return (0);
}

int	ft_update(t_program *param)
{
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}
