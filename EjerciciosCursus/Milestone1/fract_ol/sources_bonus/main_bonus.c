/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 14:15:09 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 14:15:09 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "make_engine.h"
#include "render.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_engine	engine;
	double		re;
	double		im;

	if (ac < 2)
		show_help();
	init_engine(&engine, av[1]);
	if (engine.fractal.type == JULIA && ac >= 3)
	{
		if (parse_complex_arg(av[2], &re, &im) == 0)
		{
			engine.fractal.julia_param.re = re;
			engine.fractal.julia_param.im = im;
			engine.fractal.is_julia_block = true;
		}
		else
			show_julia_error(1);
	}
	draw_fractal(&engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_event, &engine);
	mlx_loop(engine.mlx);
}
