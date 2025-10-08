/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 16:14:06 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 16:14:06 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void    set_pixel_color(t_engine *engine, int x, int y, int color)
{
    int line_len;
    int pixel_bits;
    int offset;

    if (x < 0 || x >= WIN_SIZE || y < 0 || y >= WIN_SIZE)
        return ;
    line_len = engine->image.line_len;
    pixel_bits = engine->image.pixel_bits;
    offset = (y * line_len) + ((pixel_bits / 8) * x);
    *(unsigned int *)(engine->image.addr_ptr + offset) = color;
}

int calc_fractal(t_fractal *fract, t_complex *c, int x, int y)
{
    int iter;

    iter = 0;
    if (fract->type != JULIA)
        c->im = (y / fract->zoom) + fract->offset_y;
    else if (!fract->is_julia_block)
        c->im = (fract->mouse_y / fract->zoom) + fract->offset_y;
    if (fract->type == MANDELBROT)
        iter = calc_mandelbrot(fract, c, x, y);
    else if (fract->type == JULIA)
        iter = calc_julia(fract, c, x, y);
    return (iter);
}

void    draw_fractal(t_engine *engine)
{
    static t_complex    c;
    t_fractal           *fract;
    int                 iter;
    int                 x;
    int                 y;

    x = -1;
    fract = &engine->fractal;
    mlx_clear_window(engine->mlx, engine->window);
    while(++x < WIN_SIZE)
    {
        y = -1;
        if(fract->type != JULIA)
            c.re = (x / fract->zoom) + fract->offset_x;
        else if(!fract->is_julia_block)
            c.re = (fract->mouse_x / fract->zoom) + fract->offset_x;
        while(y++)
        {
            iter = calc_fractal(fract, &c, x, y);
            set_pixe_color(engine, x, y, (iter * engine->fractal.color));
        }
    }
    mlx_put_image_to_window(engine->mlx, engine->window, \
                            engine->image.img_ptr, 0, 0);
}