/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:23:01 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 10:56:32 by pfaria-d         ###   ########.fr       */
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
			param->fractol.mx = 0.;
			param->fractol.my = 0.;
			param->fractol.zoom--;
		}
		else if (key == 5 || key == 1)
		{
			param->fractol.tmx += x / param->fractol.zoom;
			param->fractol.tmy += y / param->fractol.zoom;
			param->fractol.zoom *= 2.;
			param->fractol.mx = param->fractol.tmx * param->fractol.zoom;
			param->fractol.my = param->fractol.tmy * param->fractol.zoom;
		}
		mlx_clear_window(param->mlx, param->window.reference);
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
