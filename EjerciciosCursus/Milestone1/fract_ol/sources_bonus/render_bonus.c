/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:14:06 by diego             #+#    #+#             */
/*   Updated: 2025/10/10 00:01:42 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	change_view(int key, t_engine *engine)
{
	t_fractal	*fractal;

	fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}

void	set_pixel_color(t_engine *engine, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
		return ;
	line_len = engine->image.line_len;
	pixel_bits = engine->image.pixel_bits;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

int	calc_fractal(t_fractal *fract, t_complex *c, int x, int y)
{
	int	iter;

	iter = 0;
	if (fract->type != JULIA)
		c->im = ((double)y / fract->zoom) + fract->offset_y;
	else if (!fract->is_julia_block)
		c->im = ((double)fract->mouse_y / fract->zoom) + fract->offset_y;
	if (fract->type == MANDELBROT)
		iter = calc_mandelbrot(fract, c);
	else if (fract->type == JULIA)
		iter = calc_julia(fract, c, x, y);
	else if (fract->type == BURNING_SHIP)
		iter = calc_burning_ship(fract, c);
	else if (fract->type == TRICORN)
		iter = calc_tricorn(fract, c);
	else if (fract->type == SIERPINSKI)
		iter = calc_sierpinski(fract, c);
	return (iter);
}

static void	set_c(t_fractal *f, t_complex *c, int x)
{
	if (f->type != JULIA)
		c->re = ((double)x / f->zoom) + f->offset_x;
	else if (f->is_julia_block)
	{
		c->re = f->julia_param.re;
		c->im = f->julia_param.im;
	}
	else
		c->re = ((double)f->mouse_x / f->zoom) + f->offset_x;
}

void	draw_fractal(t_engine *e)
{
	int			x;
	int			y;
	int			iter;
	t_complex	c;

	mlx_clear_window(e->mlx, e->window);
	x = -1;
	while (++x < WIN_SIZE)
	{
		set_c(&e->fractal, &c, x);
		y = -1;
		while (++y < WIN_SIZE)
		{
			iter = calc_fractal(&e->fractal, &c, x, y);
			set_pixel_color(e, x, y, iter * e->fractal.color);
		}
	}
	mlx_put_image_to_window(e->mlx, e->window, e->image.img_ptr, 0, 0);
}
