/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:23:01 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 19:35:17 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *) param;

	if (key == 4)
		program->fractol.zoom ++;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->img.img, 0, 0);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*prog;

	prog = (t_program *)param;
	mlx_put_image_to_window(prog->mlx, prog->window.reference,
		prog->img.img, 0, 0);
	return (0);
}
