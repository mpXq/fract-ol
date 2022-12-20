/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:55:12 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 17:08:36 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgb(int rgb)
{
	int	tmp;

	tmp = rgb * .3;
	return (tmp << 24 | tmp << 16 | tmp << 8 | rgb);
}

int	ft_close(void)
{
	exit(0);
}

t_window	new_window(void	*mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);
	return (window);
}
