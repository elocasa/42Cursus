/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-07 14:50:38 by diego             #+#    #+#             */
/*   Updated: 2025-11-07 14:50:38 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	show_help(void)
{
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" +------------------ Let me help you! --------------+\n", 1);
	ft_putstr_fd(" |                                                  |\n", 1);
	ft_putstr_fd(" | Usage: ./fractol [mandelbrot / julia [re,img] /  |\n", 1);
	ft_putstr_fd(" |                  / burning_ship / tricorn        |\n", 1);
	ft_putstr_fd(" |                   / sierpinski]                  |\n", 1);
	ft_putstr_fd(" |                                                  |\n", 1);
	ft_putstr_fd(" | e.g: ./fractol mandelbrot                        |\n", 1);
	ft_putstr_fd(" |                                                  |\n", 1);
	ft_putstr_fd(" +--------------------------------------------------+\n", 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_SUCCESS);
}

void	change_color(int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
		engine->fractal.color += 0x030000;
	else if (key == KEY_E)
		engine->fractal.color += 0x003000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000300;
	else if (key == KEY_T)
		engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000003;
	else if (key == KEY_A)
		engine->fractal.color += 0x300000;
	else if (key == KEY_S)
		engine->fractal.color += 0x030000;
	else if (key == KEY_D)
		engine->fractal.color += 0x003000;
	else if (key == KEY_F)
		engine->fractal.color += 0x000300;
	else if (key == KEY_G)
		engine->fractal.color += 0x000030;
	else if (key == KEY_H)
		engine->fractal.color += 0x000003;
}

void	show_julia_error(int num)
{
	if (num == 1)
		ft_putendl_fd("Invalid Julia parameters, use (re,im)\n", 2);
	show_help();
}

void	engine_error(t_engine *engine)
{
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine, engine->image.img_ptr);
		mlx_destroy_window(engine, engine->window);
		mlx_destroy_display(engine->mlx);
		error_message("[FATAL MLX ERROR]: can't handle object creation!\n", 1);
	}
}
