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

int on_key_hook_event(int key, t_engine *engine)
{
    if((key >= KEY_Q) && (key <= KEY_Y) || (key >= KEY_A) && (key <= KEY_H))
        change_color(key, engine);
    else if(key >= KEY_LEFT && key <= KEY_UP)
        change_view(key, engine);
    else if(key >= KEY_ONE && key <= KEY_TWO)
        change_fractal(key, engine);
    else if(key == KEY_L && engine->fractal.type == JULIA)
        engine->fractal.is_julia_block ^= 1;
    else if(key == KEY_ZERO)
        reset_engine(engine, engine->fractal.type);
    else if(key == KEY_ESC)
        on_destroy_event(engine);
    draw_fractal(engine);
    return (0);
}