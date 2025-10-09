/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 17:15:20 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 17:15:20 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "render.h"
#include "make_engine.h"
#include "mlx.h"

int on_destroy_event(t_engine *engine)
{
    mlx_destroy_image(engine->mlx, engine->image.img_ptr);
    mlx_destroy_window(engine->mlx, engine->window);
    exit(EXIT_SUCCESS);
}

int on_mouse_hook_event(int key, int x, int y, t_engine *engine)
{
    t_fractal *fr;

    fr = &engine->fractal;

    if(key == MOUSE_SCRL_DOWN)
    {
        fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
        fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
        fr->zoom *= 1.3;
        if(fr->iterations < MAX_ITERATIONS)
            ++fr->iterations;
    }
    else if(key == MOUSE_SCRL_UP)
    {
        fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
        fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
        fr->zoom /= 1.3;
        if(fr->iterations < MIN_ITERATIONS)
            --fr->iterations;
    }
    draw_fractal(engine);
    return (0);

}

int on_key_hook_event(int key, t_engine *engine)
{
    if (((key >= KEY_Q) && (key <= KEY_Y)) || ((key >= KEY_A) && (key <= KEY_H)))
        change_color(key, engine);
    else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
        change_view(key, engine);
    else if (key >= KEY_ONE && key <= KEY_SIX)
        change_fractal(key, engine);
    else if (key == KEY_L && engine->fractal.type == JULIA)
        engine->fractal.is_julia_block ^= 1;
    else if (key == KEY_ZERO)
        reset_engine(engine, engine->fractal.type);
    else if (key == KEY_ESC)
        on_destroy_event(engine);
    draw_fractal(engine);
    return (0);
}

int on_mousemove_event(int x, int y, t_engine *engine)
{
    if(!(engine->fractal.type == JULIA) || engine->fractal.is_julia_block)
        return (0);
    engine->fractal.mouse_x = x;
    engine->fractal.mouse_y = y;
    draw_fractal(engine);
    return (0);
}