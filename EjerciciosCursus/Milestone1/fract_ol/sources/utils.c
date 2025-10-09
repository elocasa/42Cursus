/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-08 14:28:52 by diego             #+#    #+#             */
/*   Updated: 2025-10-08 14:28:52 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


void    error_message(char *text, int mode)
{
    if(mode == 0)
        perror(text);
    else if(text)
        ft_putstr_fd(text, 2);
    exit(EXIT_FAILURE);
}

void    ft_strlower(char *str)
{
    int i;

    if(!str)
        return ;
    i = -1;
    while(str[i++])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] +=32;
    }
}

void    print(char *str, int fd)
{
    ft_putstr_fd(str, fd);
}

void show_help()
{
    print("\n", 1);
	print(" +------------------ Let me help you! ---------------------+\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Usage: ./fractol [mandelbrot / julia / burning_ship     |\n", 1);
	print(" |                   tricorn / mandelbox /                 |\n", 1);
	print(" |                   celtic_mandelbar]                     |\n", 1);
	print(" |                                                         |\n", 1);
	print(" | e.g: ./fractol mandelbrot                               |\n", 1);
	print(" |                                                         |\n", 1);
	print(" |----------------------- KEYBOARD ------------------------|\n", 1);
	print(" |                                                         |\n", 1);
	print(" | Press ESC to close the window                           |\n", 1);
	print(" | Press one of [1-5] to move to another fractal           |\n", 1);
	print(" | Press one of [Q-Y] keys to change the color of fractal  |\n", 1);
	print(" | Press one of [A-H] keys to change the color of fractal  |\n", 1);
	print(" | Use mouse scroll to zoom in and out of the fractal      |\n", 1);
	print(" | Press the arrow keys to change the viewpoint            |\n", 1);
	print(" | Press L to lock Julia's fractal                         |\n", 1);
	print(" | Press Zero to reset the fractal                         |\n", 1);
	print(" +---------------------------------------------------------+\n", 1);
	print("\n", 1);
}