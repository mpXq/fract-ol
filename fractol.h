/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 12:42:37 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "extra/extra.h"

# ifndef MAXITERATION
#  define MAXITERATION 150
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol {
	long double	nbx;
	long double	nby;
	long double	x;
	long double	y;
	long double	tmp;
	int			rgb;
}				t_fractol;

#endif
