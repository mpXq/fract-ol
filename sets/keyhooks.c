
#include "sets.h"

int	ft_input123(t_program *param)
{
	param->fractol.tmx -= 100 / param->fractol.zoom;
	param->fractol.mx = param->fractol.tmx * param->fractol.zoom;
	mlx_clear_window(param->mlx, param->window.reference);
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}

int	ft_input125(t_program *param)
{
	param->fractol.tmy += 100 / param->fractol.zoom;
	param->fractol.my = param->fractol.tmy * param->fractol.zoom;
	mlx_clear_window(param->mlx, param->window.reference);
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}

int	ft_input126(t_program *param)
{
	param->fractol.tmy -= 100 / param->fractol.zoom;
	param->fractol.my = param->fractol.tmy * param->fractol.zoom;
	mlx_clear_window(param->mlx, param->window.reference);
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}

int	ft_input124(t_program *param)
{
	param->fractol.tmx += 100 / param->fractol.zoom;
	param->fractol.mx = param->fractol.tmx * param->fractol.zoom;
	mlx_clear_window(param->mlx, param->window.reference);
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}

int	ft_changecolor(t_program *param)
{
	if (param->fractol.rgb == 0)
		param->fractol.rgb = 0x0009EE10;
	else if (param->fractol.rgb == 0x0009EE10)
		param->fractol.rgb = 0x00EE4709;
	else if (param->fractol.rgb == 0x00EE4709)
		param->fractol.rgb = 0x0009EEE7;
	else if (param->fractol.rgb == 0x0009EEE7)
		param->fractol.rgb = 0x00EE0982;
	else if (param->fractol.rgb == 0x00EE0982)
		param->fractol.rgb = 0x009C31EA;
	else if (param->fractol.rgb == 0x009C31EA)
		param->fractol.rgb = 0x000FAF77;
	else if (param->fractol.rgb == 0x000FAF77)
		param->fractol.rgb = 0;
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}
