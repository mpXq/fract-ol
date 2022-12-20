/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:28:42 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/20 15:22:00 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static long double	power(int x)
{
	return (pow(10, -x));
}

long double	ft_atoi(const char *str)
{
	int			i;
	int			x;
	long double	y;
	long double	rep;

	i = 0.;
	y = 1.;
	x = 1;
	rep = 0.;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		rep = (rep * 10) + (str[i++] - 48);
	if (str[i++] == '.')
		while (str[i] >= '0' && str[i] <= '9')
			rep += (str[i++] - 48.0) * power(x++);
	return (rep * y);
}
