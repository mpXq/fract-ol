/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:43:26 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/21 21:14:21 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct s_fractol {
	long double			nbx;
	long double			nby;
	long double			mx;
	long double			my;
//	long double			startx;
//	long double			starty;
	long double			x;
	long double			y;
	long double			tmp;
	long double			zoom;
	int					rgb;
}				t_fractol;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_program {
	void		*mlx;
	t_data		img;
	t_window	window;
	t_fractol	fractol;
}				t_program;

# ifndef MAXITERATION
#  define MAXITERATION 150
# endif

int			ft_input(int key, int x, int y, t_program *param);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			rgb(int rgb);
void		mandelbrot_set(void);
void		julia_set(long double zx, long double zy);
t_window	new_window(void *mlx, int widht, int height, char *name);
int			ft_close(void);
int			ft_update(t_program *param);
void		mspawner(t_data img, t_fractol *mset);

#endif
