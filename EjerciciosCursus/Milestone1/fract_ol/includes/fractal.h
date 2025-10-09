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
#include <stdint.h>
#include "mlx.h"
#include "keys.h"
#include "libft.h"

#define MANDELBROT 1
#define JULIA 2
#define BURNING_SHIP 3
#define TRICORN 4
#define NEWTON 5
#define SIERPINSKI 6

#define MANDELBROT_STR "mandelbrot"
#define JULIA_STR "julia"
#define BURNING_SHIP_STR "burning_ship"
#define TRICORN_STR "tricorn"
#define NEWTON_STR "newton"
#define SIERPINSKI_STR "sierpinski"

#define WIN_SIZE 1000
#define VIEW_CHANGE_SIZE 60
#define MIN_ITERATIONS 265
#define MAX_ITERATIONS 265
#define DEFAULT_COLOR 265


typedef struct s_complex
{
    double  re;
    double  im;
}   t_complex;

typedef struct s_fractal
{
    int type;
    double  zoom;
    uint32_t    color;
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

int calc_julia(t_fractal *fract, t_complex *c, int x, int y);
int calc_mandelbrot(t_fractal *fract, t_complex *c);
int calc_burning_ship(t_fractal *fract, t_complex *c);
int calc_tricorn(t_fractal *fract, t_complex *c);
int	calc_newton(t_fractal *fract, t_complex *c);
int	calc_sierpinski(t_fractal *fract, t_complex *c);

#endif