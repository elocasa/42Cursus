/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:08:22 by diego             #+#    #+#             */
/*   Updated: 2025/10/10 00:01:37 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

void	set_fractal_type(t_engine *engine, char *str)
{
	size_t	len;

	if (!engine || !str)
		return ;
	ft_strlower(str);
	len = ft_strlen(str);
	if (ft_strncmp(str, MANDELBROT_STR, len) == 0)
		engine->fractal.type = MANDELBROT;
	else if (ft_strncmp(str, JULIA_STR, len) == 0)
		engine->fractal.type = JULIA;
	else if (ft_strncmp(str, BURNING_SHIP_STR, len) == 0)
		engine->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(str, TRICORN_STR, len) == 0)
		engine->fractal.type = TRICORN;
	else if (ft_strncmp(str, NEWTON_STR, len) == 0)
		engine->fractal.type = NEWTON;
	else if (ft_strncmp(str, SIERPINSKI_STR, len) == 0)
		engine->fractal.type = SIERPINSKI;
	else
		show_help();
}

void	reset_engine(t_engine *engine, int fractal_type)
{
	engine->fractal.type = fractal_type;
	engine->fractal.zoom = WIN_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.is_julia_block = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

void	change_fractal(int key, t_engine *engine)
{
	reset_engine(engine, MANDELBROT);
	if (key == KEY_TWO)
	{
		engine->fractal.type = JULIA;
		set_julia_defaults(&engine->fractal, 0);
	}
	else if (key == KEY_THREE)
		engine->fractal.type = BURNING_SHIP;
	else if (key == KEY_FOUR)
		engine->fractal.type = TRICORN;
	else if (key == KEY_FIVE)
		engine->fractal.type = SIERPINSKI;
}

void	init_engine(t_engine *engine, char *arg)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !arg)
		return ;
	reset_engine(engine, MANDELBROT);
	set_fractal_type(engine, arg);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[FATAL MLX ERROR]: can't do mlx_init\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE,
			">Fractol Project<");
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_SIZE, WIN_SIZE);
	engine_error(engine);
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr,
			&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_len = line_len;
	engine->image.endian = endian;
}
