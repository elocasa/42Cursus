/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:38:43 by diego             #+#    #+#             */
/*   Updated: 2025/10/10 00:00:59 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "math.h"

int calc_mandelbrot(t_fractal *fract, t_complex *c)
{
    double      re_temp;
    t_complex   z;
    int         i;

    i = -1;
    z.re = 0;
    z.im = 0;

    while((z.re * z.re + z.im * z.im) < 4 && i++ < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = 2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}

int	calc_julia(t_fractal *fract, t_complex *c, int x, int y)
{
	double	re, im, re2, im2;
	int		i;

	re = x / fract->zoom + fract->offset_x;
	im = y / fract->zoom + fract->offset_y;

	i = 0;
	while (i < fract->iterations)
	{
		re2 = re * re;
		im2 = im * im;
		if (re2 + im2 > 4.0)
			break;
		im = 2.0 * re * im + c->im;
		re = re2 - im2 + c->re;
		i++;
	}
	return (i);
}

int calc_burning_ship(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = fabs(2 * z.re * z.im) + c->im;
		z.re = fabs(re_temp);
	}
	return (i);
}


int	calc_newton(t_fractal *fract, t_complex *c)
{
	t_complex	z;
	t_complex	num;
	t_complex	den;
	t_complex	tmp;
	double		mod;
	int			i;

	z.re = c->re;
	z.im = c->im;
	i = -1;
	while (++i < fract->iterations)
	{
		num.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im - 1;
		num.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im;

        den.re = 3 * (z.re * z.re - z.im * z.im);
		den.im = 6 * z.re * z.im;

		mod = den.re * den.re + den.im * den.im;
		if (mod == 0.0)
			break;
		tmp.re = (num.re * den.re + num.im * den.im) / mod;
		tmp.im = (num.im * den.re - num.re * den.im) / mod;

		z.re = z.re - tmp.re;
		z.im = z.im - tmp.im;

		if ((tmp.re * tmp.re + tmp.im * tmp.im) < 1e-6)
			break;
	}
	return (i);
}



int calc_tricorn(t_fractal *fract, t_complex *c)
{
	double		re_temp;
	t_complex	z;
	int			i;

	i = -1;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
	{
		re_temp = z.re * z.re - z.im * z.im + c->re;
		z.im = -2 * z.re * z.im + c->im;
		z.re = re_temp;
	}
	return (i);
}

int	calc_sierpinski(t_fractal *fract, t_complex *c)
{
	int	x;
	int	y;
	int	i = 0;
	double	scale = 100.0;

	x = (int)(c->re * scale);
	y = (int)(c->im * scale);

	x = abs(x);
	y = abs(y);

	while ((x & y) == 0 && i < fract->iterations)
	{
		x >>= 1;
		y >>= 1;
		i++;
	}
	return (i);
}



