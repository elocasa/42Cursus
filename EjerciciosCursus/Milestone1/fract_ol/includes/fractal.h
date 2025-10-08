/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 14:16:23 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 14:16:23 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include <stdbool.h>
#include "mlx.h"
#include "libft.h"

#define MANDELBROT 1
#define JULIA 2

#define WIN_SIZE 500
#define MIN_ITERATIONS 265
#define MAX_ITERATIONS 265
#define DEFAULT_COLOR 265
#define MANDELBROT_STR "mandelbrot"
#define JULIA_STR "julia"

typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;

typedef struct s_fractal
{
    int type;
    double  zoom;
    u_int332_t  color;
    double  mouse_x;
    double  mouse_y;
    double  offset_x;
    double  offset_y;
    int iterations;
    bool    is_julia_block;
} t_fractal;

typedef struct s_image
{
    void    *img_ptr;
    char    *addr_ptr;
    int pixel_bits;
    int line_len;
    int endian;
} t_image;

typedef struct s_engine
{
    void *mlx;
    void *window;
    t_image image;
    t_fractal fractal;
} t_engine;
#endif