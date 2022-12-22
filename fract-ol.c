/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:32:14 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 15:05:54 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	errorprinter(void)
{
	ft_printf("Error: available fractals:\n");
	ft_printf("./fract-ol Mandelbrot\n");
	ft_printf("./fract-ol Julia n ni\n");
	return (1);
}

static int	error(int argc, char **argv)
{
	if (argc <= 1)
		return (errorprinter());
	if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
		&& ft_strncmp(argv[1], "Julia", 6) != 0)
		return (errorprinter());
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		if (argc != 2)
			return (errorprinter());
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		if (argc > 4)
			return (errorprinter());
	}
	return (0);
}

int	main(int argc, char **argv)
{
	double	zx;
	double	zy;

	zx = -1;
	zy = 0;
	if (error(argc, argv))
		return (-1);
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		mandelbrot_set();
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		if (argv[2])
			zx = ft_atoi(argv[2]);
		if (argv[3])
			zy = ft_atoi(argv[3]);
		julia_set(zx, zy);
	}
	return (0);
}
