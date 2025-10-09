/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:29:42 by diego             #+#    #+#             */
/*   Updated: 2025/10/09 23:35:39 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "fractal.h"
#include <stdio.h>

void    error_message(char *text, int mode);
void    ft_strlower(char *str);
void    show_help();
void draw_help_screen(t_engine *engine);

#endif