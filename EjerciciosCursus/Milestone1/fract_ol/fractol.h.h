/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-28 10:23:08 by diego             #+#    #+#             */
/*   Updated: 2025-09-28 10:23:08 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef FRACTOL_H
#  define FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_fractal
{
    void *mlx;
    void *win;
    void *img;
    int   *data;
    int   bpp;
    int   size_line;
    int   endian;
    int   max_iter;
    double zoom;
    double move_x;
    double move_y;
    int   fractal_type;
} t_fractal;






#endif