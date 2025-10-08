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

#include "fractal.h"

int main(int ac, char **av)
{
    t_engine    engine;
    if(ac != 2)
        show_help();
    init_engine(&engine, av[1]);
    draw_fractal(&engine);
}