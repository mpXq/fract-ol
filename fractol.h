/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:59:03 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 19:15:34 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "utils/utils.h"
# include "sets/sets.h"

# ifndef MAXITERATION
#  define MAXITERATION 10
# endif

# ifndef ZX
#  define ZX "-1"
# endif

# ifndef ZY
#  define ZY "0"
# endif

int	ft_input(int key, void *param);
int	ft_update(void *param);

#endif
