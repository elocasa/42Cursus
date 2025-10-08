/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 16:18:46 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 16:18:46 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_

#include "fractal.h"


void    set_pixel_color(t_engine *engine, int x, int y, int color);
void    draw_fractal(t_engine *engine);
int calc_fractal(t_fractal *fract, t_complex *c, int x, int y);

#endif